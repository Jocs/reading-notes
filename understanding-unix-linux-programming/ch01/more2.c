#include <stdio.h>
#include <stdlib.h>

#define LINENUM 512
#define PAGENUM 12

void do_more(FILE* fp);
int see_more(FILE* fp);

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
  FILE* tty;

  if ((tty = fopen("/dev/tty", "r")) == NULL) {
    exit(EXIT_FAILURE);
  }

  while (fgets(line, LINENUM, fp)) {
    if (num_of_line == PAGENUM) {
      more_line = see_more(tty);
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

  fclose(tty);
}

int see_more(FILE* fp) {
  int ch;
  printf("\033[7m more? \033[m");
  while ((ch = getchar()) != EOF) {
    if (ch != '\n') {
      while (fgetc(fp) != '\n')
        continue;
    }

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
