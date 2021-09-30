#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>

#define TSIZE 45

struct film {
  char title[TSIZE];
  int rating;
};

typedef struct film Item;
typedef struct node {
  Item item;
  struct node *next;
} Node;

typedef struct list {
  Node *head;
  Node *tail;
  int size;
} List;

void InitializeList(List *plist);
bool ListIsEmpty(const List *plist);
bool ListIsFull(const List *plist);
unsigned int ListSize(const List *plist);
bool AppendItem(Item item, List *plist);
bool RemoveLastItem(List *plist);
void Traverse(const List *plist, void (*pfun)(Item item));
void EmptyList(List *plist);
#endif