#include <grp.h>
#include <stdio.h>
#include <stdlib.h>

// print group info and users in group.
void showGroupUsers(const struct group *gmp);

int main(void) {
  struct group *tmp;
  setgrent();

  while ((tmp = getgrent()) != NULL) {
    showGroupUsers(tmp);
  }

  endgrent();
  exit(EXIT_SUCCESS);
}

void showGroupUsers(const struct group * gmp) {
  printf("Group: %s\n", gmp->gr_name);
  printf("    Group Users: ");

  for (int i = 0; gmp->gr_mem[i] != NULL; i++) {
    printf("%s ", gmp->gr_mem[i]);
  }

  printf("\n");
}