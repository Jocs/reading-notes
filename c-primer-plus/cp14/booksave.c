#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define TITLE_SIZE 40
#define AUTHOR_SIZE 40
#define MAXBKS 20

struct book
{
  char title[TITLE_SIZE];
  char author[AUTHOR_SIZE];
  float value;
};

int main(void) {
  struct book library[MAXBKS];
  int count = 0;
  int index, filecount;
  FILE *pbooks;
  int size = sizeof(struct book);
  if ((pbooks = fopen("book.dat", "a+b")) == NULL) {
    fputs("Can't open book.dat file\n", stderr);
    exit(EXIT_FAILURE);
  }

  rewind(pbooks);
  while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
    if (count == 0)
      puts("Current contents of book.dat\n");
    printf("library: title = %s, author = %s, value = %.2f\n", library[count].title, library[count].author, library[count].value);
    count++;
  }

  filecount = count;
  if (count == MAXBKS) {
    fputs("The book.dat file is full.\n", stderr);
    exit(EXIT_FAILURE);
  }

  puts("Please add new book titles.");
  while (count < MAXBKS && s_get(library[count].title, TITLE_SIZE) != NULL && library[count].title[0] != '\0') {
    puts("Now enter the author.");
    s_get(library[count].author, AUTHOR_SIZE);
    puts("Now enter the value.");
    scanf("%f", &library[count++].value);
    while (getchar() != '\n')
      continue;
    if (count < MAXBKS)
      puts("Enter the next title.");
  }

  if (count > 0) {
    puts("Here is the list of books.");
    for (index = 0; index < count; index++)
      printf("library: title = %s, author = %s, value = %.2f\n", library[index].title, library[index].author, library[index].value);
    fwrite(&library[filecount], size, count - filecount, pbooks);
  } else {
    puts("No books?");
  }

  puts("Bye.");
  fclose(pbooks);

  return 0;
}
