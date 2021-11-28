#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define oops(m,x) {perror(m);exit(x);}

void do_dc(int todc[2], int fromdc[2]);
void do_bc(int todc[2], int fromdc[2]);

int main(void) {
  int pid, todc[2], fromdc[2];

  // make two pipes
  if (pipe(todc) == -1 || pipe(fromdc) == -1) {
    oops("pipe failed", 1);
  }

  if ((pid = fork()) == -1) {
    oops("fork", 1);
  } else if (pid == 0) {
    // child process
    do_dc(todc, fromdc);
  } else {
    do_bc(todc, fromdc);
    wait(NULL);
  }

  exit(0);
}

void do_dc(int todc[2], int fromdc[2]) {
  if (dup2(todc[0], 0) == -1) {
    oops("dup2", 1);
    close(todc[0]);
    close(todc[1]);
  }

  if (dup2(fromdc[1], 1) == -1) {
    oops("dup2", 1);
    close(fromdc[0]);
    close(fromdc[1]);
  }

  execlp("dc", "dc", "-", NULL);
  oops("Cannot run dc", 5);
}

void do_bc(int todc[2], int fromdc[2]) {
  char message[BUFSIZ], operator;
  int num1, num2;
  // setup
  close(todc[0]);
  close(fromdc[1]);
  FILE* fin = fdopen(fromdc[0], "r");
  FILE* fout = fdopen(todc[1], "w");

  puts("tinybc: ");
  while (fgets(message, BUFSIZ, stdin) != NULL && message[0] != '\n') {
    if (sscanf(message, "%d%[-+*/^]%d", &num1, &operator, &num2) != 3) {
      printf("syntax error\n");
      continue;
    }

    if (fprintf(fout, "%d\n%d\n%c\np\n", num1, num2, operator) == EOF) {
      fprintf(stderr, "error");
      exit(1);
    }

    fflush(fout);

    if (fgets(message, BUFSIZ, fin) == NULL) {
      break;
    }

    printf("%d %c %d = %s\n", num1, operator, num2, message);

    puts("try another tinybc: ");
  }

  fclose(fout);
  fclose(fin);
}

