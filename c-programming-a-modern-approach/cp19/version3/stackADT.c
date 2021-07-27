#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"
#include <stdbool.h>

typedef int Item;

struct node {
  Item data;
  struct node *next;
};

struct stack_type {
  struct node *top;
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
    terminate("Error in create: no enough memory;");
  }
  s->top = NULL;
  return s;
}

void destory(Stack s)
{
  make_empty(s);
  free(s);
}

void make_empty(Stack s)
{
  while (!is_empty(s)) {
    pop(s);
  }
}

bool is_empty(Stack s)
{
  return s->top == NULL;
}

bool is_full(Stack s)
{
  return false;
}

void push(Stack s, Item i)
{
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    terminate("Error in push: no memory avaliable");
  }
  new_node->data = i;
  new_node->next = s->top;
  s->top = new_node;
}

Item pop(Stack s)
{
  Item i;
  struct node *old_node;
  if (is_empty(s)) {
    terminate("Error in pop: stack is empty!");
  }
  old_node = s->top;
  i = old_node->data;
  s->top = old_node->next;
  free(old_node);
  return i;
}