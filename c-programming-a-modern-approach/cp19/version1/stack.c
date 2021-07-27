#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node {
  int data;
  struct node *next;
};

static struct node *top = NULL;

static void temenate(const char *message)
{
  printf("%s", message);
  exit(EXIT_FAILURE);
}

void make_empty(void)
{
  while (!is_empty()) {
    pop();
  }
}

bool is_empty(void)
{
  return top == NULL;
}

bool is_full(void)
{
  return false;
}

void push(int i)
{
  struct node *new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    temenate("Error in push: there is no enough memory");
  }
  new_node -> data = i;
  new_node -> next = top;
  top = new_node;
}

int pop(void)
{
  if (is_empty()) {
    temenate("Error in pop: stack is empty");
  }
  struct node *old_node;
  int i;
  old_node = top;
  i = top -> data;
  top = top -> next;
  free(old_node);
  return i;
}

