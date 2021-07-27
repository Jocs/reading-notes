#include <stdio.h>
#include <stdlib.h>
#include "read_line.h"

#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN + 1];
  int on_hand;
  struct part *next;
};

struct part *inventory = NULL;

struct part *find_part(int number);
void insert(void);
void update(void);
void search(void);
void print(void);

int main(void)
{
  char code;
  for (;;) {
    printf("Enter command code:");
    scanf(" %c", &code);

    switch (code) {
      case 'i': insert();
        break;
      case 'u': update();
        break;
      case 's': search();
        break;
      case 'p': print();
        break;
      case 'q':
        return 0;
      default:
        printf("Illegal code\n");
        break;
    }
    printf("\n");
  }
  return 0;
}

struct part *find_part(int number)
{
  struct part *p;
  for (p = inventory; p != NULL && number > p -> number; p = p -> next )
    ;
  if (p != NULL && p -> number == number)
    return p;
  return NULL;
}

void insert(void)
{
  struct part *cur, *prev;
  struct part *new_node = malloc(sizeof(struct part));

  if (new_node == NULL) {
    printf("NO SPACE LEFT\n");
    return;
  }

  printf("Enter part number:");
  scanf("%d", &(new_node -> number));

  printf("Enter part name:");
  read_line(new_node -> name, NAME_LEN);

  printf("Enter stock:");
  scanf(" %d", &(new_node -> on_hand));

  for (prev = NULL, cur = inventory; cur != NULL && new_node -> number >= cur -> number; prev = cur, cur = cur -> next)
    ;
  if (cur && cur -> number == new_node -> number) {
    printf("part already existed\n");
    free(new_node);
    return;
  }

  new_node->next = cur;

  if (prev == NULL) {
    inventory = new_node;
  } else {
    prev -> next = new_node;
  }
}

void update(void)
{
  int number;
  int change;
  struct part *p;
  printf("Enter part number:");
  scanf("%d", &number);
  p = find_part(number);
  if (!p) {
    printf("Not find part!\n");
  } else {
    printf("Enter change:");
    scanf("%d", &change);
    p -> on_hand += change;
  }
}

void search(void)
{
  int number;
  struct part *p;
  printf("Enter part number:");
  scanf(" %d", &number);
  p = find_part(number);
  if (!p) {
    printf("Not find part!\n");
  } else {
    printf("part name: %s\n", p -> name);
    printf("part stock:%d\n", p -> on_hand);
  }
}

void print(void)
{
  struct part *p;
  for (p = inventory; p != NULL; p = p -> next) {
    printf("%-5d%10s%5d\n", p -> number, p -> name, p -> on_hand);
  }
}