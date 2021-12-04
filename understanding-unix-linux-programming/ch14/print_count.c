#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM 5

int count = 0;

void* print_count(void*);

int main(void) {
  pthread_t t1;
  pthread_create(&t1, NULL, print_count, NULL);
  for (int i = 0; i < NUM; i++) {
    count++;
    sleep(1);
  }
  pthread_join(t1, NULL);

  exit(0);
}

void* print_count(void* msg) {
  for (int i = 0; i < NUM; i++) {
    printf("%d\n", count);
    fflush(stdout);
    sleep(1);
  }

  return NULL;
}