#include <stdio.h>
#include <string.h>
#include "common.h"

#define TITLE_SIZE 40
#define AUTHOR_SIZE 40
#define MAX_BOOKS 20

struct book
{
  char title[TITLE_SIZE];
  char author[AUTHOR_SIZE];
  float value;
};

int main(void) {
  struct book library[MAX_BOOKS];
  puts("Input book name:");
  int count = 0;
  int index;
  while (count < MAX_BOOKS && s_get(library[count].title, TITLE_SIZE) != NULL && library[count].title[0] != '\0')
  {
    puts("Enter author.");
    s_get(library[count].author, AUTHOR_SIZE);
    puts("Enter price");
    scanf("%f", &library[count].value);
    while (getchar() != '\n')
      continue;
    count++;
    if (count < MAX_BOOKS)
      puts("Enter another book name.");
  }
  if (count > 0) {
    for (index = 0; index < count; index++) {
      printf("library: title = %s, author = %s, value = %.2f\n", library[index].title, library[index].author, library[index].value);
    }
  }

  return 0;
}