#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define NLEN 30

struct namect {
  char * firstname;
  char * lastname;
  int letters;
};

void getinfo(struct namect *);
void makeinfo(struct namect *);
void showinfo(struct namect *);
void cleanup(struct namect *);

int main(void) {
  struct namect person;

  getinfo(&person);
  makeinfo(&person);
  showinfo(&person);
  cleanup(&person);

  return 0;
}

void getinfo(struct namect * person) {
  char *temp = (char *)malloc(NLEN * sizeof(char));
  puts("Input the firstname:");
  s_get(temp, NLEN);
  person->firstname = (char *)malloc(strlen(temp) + 1);
  strcpy(person->firstname, temp);
  puts("Enter the lastname:");
  s_get(temp, NLEN);
  person->lastname = (char *)malloc(strlen(temp) + 1);
  strcpy(person->lastname, temp);
}

void makeinfo(struct namect * person) {
  person->letters = (int)strlen(person->firstname) + (int)strlen(person->lastname);
}

void showinfo(struct namect * person) {
  fprintf(stdout, "%s %s has %d letters.\n", person->firstname, person->lastname, person->letters);
}

void cleanup(struct namect * person) {
  free(person->firstname);
  free(person->lastname);
}
