#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>

void* count_word(void* name);

struct arg_set {
  char* filename;
  int count;
};

int main(int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage ./a.out filename1 filename2.\n");
    exit(1);
  }

  pthread_t t1, t2;
  struct arg_set set1;
  struct arg_set set2;
  set1.filename = argv[1];
  set1.count = 0;
  set2.filename = argv[2];
  set2.count = 0;
  pthread_create(&t1, NULL, count_word, &set1);
  pthread_create(&t2, NULL, count_word, &set2);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("WC: %d\n", set1.count + set2.count);

  exit(0);
}

void* count_word(void* arg) {
  struct arg_set* ar = (struct arg_set*)arg;
  char* filename = ar->filename;
  FILE* fp;
  int c;
  int prev = '\0';

  if ((fp = fopen(filename, "r")) != NULL) {
    while ((c = getc(fp)) != EOF) {
      if (!isalnum(c) && isalnum(prev)) {
        ar->count++;
      }
      prev = c;
    }
  }

  fclose(fp);

  return NULL;
}