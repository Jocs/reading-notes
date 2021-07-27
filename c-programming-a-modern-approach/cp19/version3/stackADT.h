#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h> // C99 only

typedef struct stack_type *Stack;

Stack create(void);
void destory(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, int i);
int pop(Stack s);

#endif