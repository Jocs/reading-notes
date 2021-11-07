#include <stdio.h>
#include <stdlib.h>

#define LINENUM 512
#define PAGENUM 12

void do_more(FILE* fp);
int see_more(void);

int main(int argc, char** argv) {
  FILE* fp;

  if (argc == 1) {
    do_more(stdin);
  } else {
    while (--argc) {
      if ((fp = fopen(*++argv, "r")) == NULL) {
        exit(EXIT_FAILURE);
      }
      do_more(fp);
      fclose(fp);
    }
  }

  exit(EXIT_SUCCESS);
}

void do_more(FILE* fp) {
  char line[LINENUM];
  int num_of_line = 0;
  int more_line;

  while (fgets(line, LINENUM, fp)) {
    if (num_of_line == PAGENUM) {
      more_line = see_more();
      printf("more line: %d\n", more_line);
      if (more_line == 0) {
        break;
      } else {
        num_of_line -= more_line;
      }
    }
    num_of_line++;
    fputs(line, stdout);
  }
}

int see_more(void) {
  int ch;
  printf("\033[7m more? \033[m");
  while ((ch = getchar()) != EOF) {
    while (getchar() != '\n')
      continue;
    if (ch == 'q') {
      return 0;
    } else if (ch == ' ') {
      return PAGENUM;
    } else if (ch == '\n') {
      return 1;
    }
  }
  return 0;
}
