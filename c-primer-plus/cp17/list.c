#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

void InitializeList(List *plist) {
  plist->head = NULL;
  plist->tail = NULL;
  plist->size = 0;
}

bool ListIsEmpty(const List *plist) {
  return plist->size == 0;
}

bool ListIsFull(const List *plist) {
  Node *temp = (Node *)malloc(sizeof(Node));
  bool result = temp == NULL;
  free(temp);

  return result;
}

unsigned int ListSize(const List *plist) {
  return plist->size;
}

bool AppendItem(Item item, List *plist) {
  if (ListIsFull(plist)) {
    return false;
  }
  Node *cur = (Node *)malloc(sizeof(Node));
  cur->item = item;
  if (!plist->head) {
    plist->head = cur;
    plist->tail = cur;
  } else {
    plist->tail->next = cur;
    plist->tail = cur;
  }
  (plist->size)++;

  return true;
}

bool RemoveLastItem(List *plist) {
  // TODO
  return false;
}

void Traverse(const List *plist, void (*pfun)(Item item)) {
  Node *cur = plist->head;
  while (cur != NULL) {
    (*pfun)(cur->item);
    cur = cur->next;
  }
}

void EmptyList(List *plist) {
  Node *cur = plist->head;

  while (cur != NULL) {
    plist->head = cur->next;
    free(cur);
    cur = plist->head;
  }

  InitializeList(plist);
}
