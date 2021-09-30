#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

void show_movie(Item item);
char * s_gets(char *st, int n);

int main(void) {
  List *movies = (List *)malloc(sizeof(List));
  Item temp;
  InitializeList(movies);
  if (ListIsFull(movies)) {
    puts("No memeory available! Bye!");
    free(movies);
    exit(EXIT_FAILURE);
  }

  puts("Enter first movie title?");
  while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0') {
    puts("Enter the rating?");
    scanf("%d", &temp.rating);
    while (getchar() != '\n')
      continue;

    if (!AppendItem(temp, movies)) {
      puts("Append item failed");
      break;
    }
    if (ListIsFull(movies)) {
      puts("No memeory available after append one movie! Bye!");
      break;
    }
    puts("Enter another movie title?");
  }

  if (ListIsEmpty(movies)) {
    puts("movies is empty.");
  } else {
    fprintf(stdout, "Here is the movie list(%d movies):\n", ListSize(movies));
    Traverse(movies, show_movie);
  }
  free(movies);
  return 0;
}

void show_movie(Item item) {
  printf("%-20s, raiting: %d\n", item.title, item.rating);
}

char * s_gets(char *st, int n) {
  char *ret_val;
  char *find;
  ret_val = fgets(st, n, stdin);

  if (ret_val != NULL) {
    find = strchr(st, '\n');
    if (find) {
      *find = '\0';
    } else {
      while (getchar() != '\n')
        continue;
    }
  }

  return ret_val;
}