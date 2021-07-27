#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"
#include <stdbool.h>

#define MAX_STACK_SIZE 100

struct stack_type {
  int contents[MAX_STACK_SIZE];
  int top;
};

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Stack create(void)
{
  Stack s = malloc(sizeof(struct stack_type));
  if (s == NULL) {
    terminate("Error in create: no enough memory!");
  }

  s -> top = 0;
  return s;
}
void destory(Stack s)
{
  free(s);
}
void make_empty(Stack s)
{
  s -> top = 0;
}
bool is_empty(Stack s)
{
  return s -> top == 0;
}
bool is_full(Stack s)
{
  return s -> top == MAX_STACK_SIZE;
}
void push(Stack s, int i)
{
  if (is_full(s)) {
    terminate("Error in push: no enough memory!");
  }
  s->contents[s->top++] = i;
}
int pop(Stack s)
{
  if (is_empty(s)) {
    terminate("Error in pop: stack is empty");
  }
  return s->contents[--s->top];
}