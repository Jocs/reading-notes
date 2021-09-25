#include <stdio.h>
#include <string.h>
#include "common.h"
#define NLEN 30

struct namect {
  char firstname[NLEN];
  char lastname[NLEN];
  int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(struct namect *);

int main(void) {
  struct namect person;

  getinfo(&person);
  makeinfo(&person);
  showinfo(&person);

  return 0;
}

void getinfo(struct namect * person) {
  puts("Input the firstname:");
  s_get(person->firstname, NLEN);
  puts("Enter the lastname:");
  s_get(person->lastname, NLEN);
}

void makeinfo(struct namect * person) {
  person->letters = (int)strlen(person->firstname) + (int)strlen(person->lastname);
}

void showinfo(struct namect * person) {
  fprintf(stdout, "%s %s has %d letters.\n", person->firstname, person->lastname, person->letters);
}
