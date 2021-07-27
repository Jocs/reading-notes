#include <stdio.h>
#include <stdarg.h>

void miniprintf(char *fms, ...);

int main(void)
{
  miniprintf("hello %s %d %f", "world", 34, 34.56);
}

void miniprintf(char *fms, ...)
{
  va_list pn;
  char *p, *sval;
  int ival;
  double dval;
  va_start(pn, fms);
  for (p = fms; *p != '\0'; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    switch (*++p) {
      case 'd':
        ival = va_arg(pn, int);
        printf("%d", ival);
        break;
      case 'f':
        dval = va_arg(pn, double);
        printf("%f", dval);
        break;
      case 's':
        for (sval = va_arg(pn, char *); *sval; sval++)
          putchar(*sval);
        break;
      default:
        putchar(*p);
        break;
    }
  }
  va_end(pn);
}