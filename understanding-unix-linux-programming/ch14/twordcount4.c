#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <string.h>

void create_thread(char* filename);
void* count_word(void* name);

struct arg_set {
  char filename[BUFSIZ];
  int count;
};

struct arg_set* mailbox;

int reports_in = 0;
int total_count = 0;

pthread_cond_t flag = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char** argv) {
  if (argc == 1) {
    fprintf(stderr, "Usage ./a.out filename1 [...filename2]\n");
    exit(1);
  }

  for (int i = 1; i < argc; i++) {
    create_thread(argv[i]);
  }

  while (reports_in < argc - 1) {
    printf("MAIN: waiting for flag to go up\n");
    pthread_cond_wait(&flag, &lock);
    printf("MAIN: WOW! flag was raised, I have the lock\n");
    printf("%7d, %s\n", mailbox->count, mailbox->filename);
    total_count += mailbox->count;
    mailbox = NULL;
    pthread_cond_signal(&flag);
    reports_in++;
  }

  printf("WC: %d\n", total_count);

  exit(0);
}

void create_thread(char* filename) {
  pthread_t t;
  pthread_attr_t attr;
  // FIXME: free set...
  struct arg_set* set = (struct arg_set*)malloc(sizeof(struct arg_set));
  strcpy(set->filename, filename);
  set->count = 0;

  printf("set %p, %s\n", &t, filename);

  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  pthread_create(&t, &attr, count_word, set);
}

void* count_word(void* arg) {
  struct arg_set* ar = arg;
  char* filename = ar->filename;
  FILE* fp;
  int c;
  int prev = '\0';
  printf("opened filename: %s\n", filename);
  if ((fp = fopen(filename, "r")) != NULL) {
    while ((c = getc(fp)) != EOF) {
      if (!isalnum(c) && isalnum(prev)) {
        ar->count++;
      }
      prev = c;
    }
  }

  fclose(fp);

  printf("Count %s: waiting to get lock\n", filename);
  pthread_mutex_lock(&lock);
  printf("Count %s: have lock, storing data\n", filename);
  if (mailbox != NULL) {
    pthread_cond_wait(&flag, &lock);
  }

  mailbox = ar;
  printf("Count %s: raising flag\n", filename);
  pthread_cond_signal(&flag);
  printf("Count %s: unlocking box\n", filename);
  pthread_mutex_unlock(&lock);

  return NULL;
}