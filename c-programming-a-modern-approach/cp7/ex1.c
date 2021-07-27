#include <stdio.h>
#include <ctype.h>

int main(void)
{
  char a = 'a';
  char b;
  int i = 0;
  printf("size of %zu\n", sizeof i);
  printf("%c\n", toupper(a));
  do {
    scanf("%c", &b);
    printf("You enter is: %c", b);
  } while (b != '\n');

  printf("enter a message!\n");
  while (getchar() != '\n')
    i++;
  printf("The length of message is: %d\n", i);
}