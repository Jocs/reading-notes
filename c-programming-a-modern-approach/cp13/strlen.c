#include <stdio.h>

size_t strlen(const char *s);

int main(void)
{
  char *str = "hello world";
  printf("The len of str is: %lu\n", strlen(str));
}

size_t strlen(const char *s)
{
  size_t i;
  for (i = 0; *s != '\0'; s++) {
    i++;
  }
  return i;
}