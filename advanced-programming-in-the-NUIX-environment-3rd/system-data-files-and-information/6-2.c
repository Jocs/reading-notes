#include <pwd.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct passwd *getPwByName(const char *name);

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: ./a.out username\n");
    exit(EXIT_FAILURE);
  }

  struct passwd *pwd = getPwByName(argv[1]);

  if (pwd != NULL)
    printf("uid: %d, uname: %s\n", pwd->pw_uid, pwd->pw_name);
  else
    puts("not find user");

  exit(0);
}

struct passwd *getPwByName(const char *name) {
  struct passwd *tep;

  setpwent();
  while ((tep = getpwent()) != NULL)
    if (strcmp(name, tep->pw_name) == 0)
      break;

  endpwent();

  return tep;
}