#include <stdio.h>

#define PRINT_INT(n) printf("%d", n)
#define PRINT_S(s) printf("%s", s)
#define NELEMS(n) ((int) (sizeof(n) / sizeof(n[0])))

int main(void)
{
  int s[] = { 1, 3 };
  PRINT_INT(__LINE__);
  printf("\n");
  PRINT_S(__FILE__ "\n");
  #if defined(PRINT_INT)
  printf("defined PRINT_INT\n");
  printf("Size of 'hello' is %d\n", NELEMS(s));
  #endif
  return 0;
}