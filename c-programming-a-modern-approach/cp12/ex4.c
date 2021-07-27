#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100

/* wxternal variables */

int contents[STACK_SIZE];
int *top_p;

void make_empty(void)
{
  top_p = contents;
}

bool is_empty(void)
{
  return top_p == contents;
}

bool is_full(void)
{
  return top_p == contents + STACK_SIZE;
}

void push(int i)
{
  if (is_full()) {
    printf("stack overflow");
  } else {
    *top_p++ = i;
  }
}

int pop(void)
{
  if (is_empty()) {
    printf("underfolow");
    return -1;
  } else {
    return *(--top_p);
  }
}

int main(void)
{
  int a;
  make_empty();
  push(3);
  push(4);
  a = pop();
  printf("%d", a);
}
