#include <stdio.h>
#include <string.h>
#include "common.h"

#define NLEN 30

struct namect {
  char firstname[NLEN];
  char lastname[NLEN];
  int letters;
};

struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);

int main(void) {
  struct namect person;

  person = getinfo();
  person = makeinfo(person);
  showinfo(person);

  return 0;
}

struct namect getinfo(void) {
  struct namect temp;
  puts("Input the firstname:");
  s_get(temp.firstname, NLEN);
  puts("Enter the lastname:");
  s_get(temp.lastname, NLEN);

  return temp;
}

struct namect makeinfo(struct namect person) {
  person.letters = (int)strlen(person.firstname) + (int)strlen(person.lastname);
  return person;
}

void showinfo(struct namect person) {
  fprintf(stdout, "%s %s has %d letters.\n", person.firstname, person.lastname, person.letters);
}
