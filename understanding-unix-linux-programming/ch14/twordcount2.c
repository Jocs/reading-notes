#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>

int wordcount = 0;
pthread_mutex_t counter_lock = PTHREAD_MUTEX_INITIALIZER;
void* count_word(void* name);

int main(int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage ./a.out filename1 filename2.\n");
    exit(1);
  }

  pthread_t t1, t2;
  pthread_create(&t1, NULL, count_word, argv[1]);
  pthread_create(&t2, NULL, count_word, argv[2]);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("WC: %d\n", wordcount);

  exit(0);
}

void* count_word(void* name) {
  char* filename = name;
  FILE* fp;
  int c;
  int prev = '\0';

  if ((fp = fopen(filename, "r")) != NULL) {
    while ((c = getc(fp)) != EOF) {
      if (!isalnum(c) && isalnum(prev)) {
        pthread_mutex_lock(&counter_lock);
        wordcount++;
        pthread_mutex_unlock(&counter_lock);
      }
      prev = c;
    }
  }

  fclose(fp);

  return NULL;
}