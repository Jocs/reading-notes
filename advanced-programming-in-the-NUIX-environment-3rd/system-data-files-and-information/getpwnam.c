#include <stdio.h>
#include <pwd.h>
#include <stdlib.h>

int main(void) {
  struct passwd *pwd;
  pwd = getpwnam("ransixi");
  printf("uid: %d, name: %s\n", pwd->pw_uid, pwd->pw_name);
  exit(0);
}