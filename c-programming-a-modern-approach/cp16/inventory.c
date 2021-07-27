#include <stdio.h>
#include <stdlib.h>
#include "read_line.h"

#define NAME_LEN 25
#define INIT_PART_LEN 10

int part_len = INIT_PART_LEN;

struct part
{
  int number;
  char name[NAME_LEN + 1];
  int stock;
};

int find_index(int number, int *num_parts, struct part inventory[]);
void search(int *num_part, struct part inventory[]);
void insert(int *num_part, struct part inventory[]);
void update(int *num_part, struct part inventory[]);
void print(int *num_part, struct part inventory[]);
void save(int *num_parts, struct part inventory[]);
void read(int *num_parts, struct part inventory[]);

int compare_parts(const void *p, const void *q);

int find_index(int number, int *num_parts, struct part *inventory)
{
  int i;
  for (i = 0; i < *num_parts; i++) {
    if (inventory[i].number == number)
      return i;
  }
  return -1;
}

void search(int *num_parts, struct part *inventory)
{
  int number, i;
  printf("Enter part number:");
  scanf("%d", &number);
  i = find_index(number, num_parts, inventory);
  printf("Part name: %s\n", inventory[i].name);
  printf("Stock left: %d\n", inventory[i].stock);
}

void insert(int *num_parts, struct part *inventory)
{
  if (*num_parts >= part_len) {
    part_len *= 2;
    inventory = realloc(inventory, sizeof(struct part) * part_len);
  } else {
    printf("Enter part number:");
    scanf("%d", &inventory[*num_parts].number);
    printf("Enter part name:");
    read_line(inventory[*num_parts].name, (int) NAME_LEN);
    printf("Enter quantity on hand:");
    scanf("%d", &inventory[*num_parts].stock);
    (*num_parts)++;
  }
}

void update(int *num_parts, struct part *inventory)
{
  int quality;
  int number, i;
  printf("Enter part number:");
  scanf("%d", &number);
  printf("Enter stock change:");
  scanf("%d", &quality);
  i = find_index(number, num_parts, inventory);
  inventory[i].stock += quality;
  printf("The stock is %d now\n", inventory[i].stock);
}

void save(int *num_parts, struct part inventory[])
{
  char name[50];
  printf("Enter file of output filename:");
  scanf(" %s", name);

  FILE *fp = fopen(name, "w+");
  if (fp == NULL) {
    printf("Can not open file %s", name);
    exit(EXIT_FAILURE);
  }

  fwrite(inventory, sizeof(struct part), *num_parts, fp);
  fclose(fp);
}

void read(int *num_parts, struct part inventory[])
{
  char name[50];
  int n;
  printf("Enter filename to open:");
  scanf(" %s", name);
  printf("You enter filename is %s\n", name);
  FILE *fp = fopen(name, "r");
  if (fp == NULL) {
    printf("Can not open file %s", name);
    exit(EXIT_FAILURE);
  }
  *num_parts = fread(inventory, sizeof(struct part), NAME_LEN, fp);
  fclose(fp);
}

int compare_parts(const void *p, const void *q)
{
  return ((struct part *) p) -> number - ((struct part *) q) -> number;
}

void print(int *num_parts, struct part *inventory)
{
  int i;
  printf("Part Number      Part Name      Quantity on Hand\n");
  for (i = 0; i < *num_parts; i++) {
    printf("%-17d%-15s%16d\n", inventory[i].number, inventory[i].name, inventory[i].stock);
  }
}

int main(void)
{
  int num_parts = 0;
  char command;
  struct part *inventory = malloc(sizeof (struct part) * part_len);

  if (inventory == NULL) {
    printf("There are no enough memory\n");
    exit(EXIT_FAILURE);
  }

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &command);
    switch (command) {
      case 'i':
        insert(&num_parts, inventory);
        break;
      case 's':
        search(&num_parts, inventory);
        break;
      case 'u':
        update(&num_parts, inventory);
        break;
      case 'p':
        qsort(inventory, num_parts, sizeof(struct part), compare_parts);
        print(&num_parts, inventory);
        break;
      case 'd':
        qsort(inventory, num_parts, sizeof(struct part), compare_parts);
        save(&num_parts, inventory);
        break;
      case 'r':
        read(&num_parts, inventory);
        break;
      case 'q':
        return 0;
      default: printf("Illegal code\n");
        break;
    }
    printf("\n");
  }
}
