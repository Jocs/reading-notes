#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM 5

void* print_msg(void* msg);

int main(void) {
  pthread_t t1, t2;
  pthread_create(&t1, NULL, print_msg, "hello\n");
  pthread_create(&t2, NULL, print_msg, "world\n");
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  exit(0);
}

void* print_msg(void* msg) {
  int i;
  for (i = 0; i < NUM; i++) {
    printf("%s", (char*)msg);
    fflush(stdout);
    sleep(1);
  }

  return NULL;
}