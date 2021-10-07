#include <stdio.h>
#include <stdlib.h>

#define AUTHOR_LEN 20

struct book {
  char author[AUTHOR_LEN];
  int price;
};

int main(void) {
  FILE *fp;
  struct book my_book = {
    "ransixi",
    15
  };
  struct book book_to;
  if ((fp = fopen("test", "w+")) == NULL)
  {
    puts("open error");
    exit(EXIT_FAILURE);
  }

  fwrite(&my_book, sizeof(my_book), 1, fp);
  rewind(fp);
  fread(&book_to, sizeof(my_book), 1, fp);
  printf("name: %s, price: %d\n", book_to.author, book_to.price);
  fclose(fp);
  exit(0);
}