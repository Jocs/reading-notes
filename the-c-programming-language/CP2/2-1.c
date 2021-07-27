#include <limits.h>
#include <stdio.h>

enum boolean { YES, NO };

int main() {
  printf("Unsign values\n");
  printf("char max: %u \n", UCHAR_MAX);
  printf("int max: %u \n", UINT_MAX);
  printf("short max: %u \n", USHRT_MAX);
  printf("long int max: %lu \n", ULONG_MAX);
  printf("Signed values\n");
  printf("char min: %d\n", CHAR_MIN);
  printf("char max: %d\n", CHAR_MAX);
  printf("short min: %d\n", SHRT_MIN);
  printf("short max: %d\n", SHRT_MAX);
  printf("int min: %d\n", INT_MIN);
  printf("int max: %d\n", INT_MAX);
  printf("long int min: %ld\n", LONG_MIN);
  printf("long int max: %ld\n", LONG_MAX);

  printf("enum boolean YES: %d, NO: %d\n", YES, NO);
}