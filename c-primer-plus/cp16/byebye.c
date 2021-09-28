#include <stdio.h>
#include <stdlib.h>

void sign_off(void);
void too_bad(void);

int main(void) {
  atexit(sign_off);
  int n;
  puts("Enter an integer:");
  if (scanf("%d", &n) != 1) {
    puts("It's not an integer.");
    atexit(too_bad);
    exit(EXIT_FAILURE);
  }
  printf("The number %d is %s\n", n, n % 2 == 0 ? "even" : "odd");

  exit(0);
}

void sign_off(void) {
  puts("sign off");
}

void too_bad(void) {
  puts("too bad");
}