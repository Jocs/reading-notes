
#include <stdio.h>
#include <ctype.h>

double atof(char s[])
{
  double val, power;
  int i, j, val2, sign, powerSign;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    /* skip white space */
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  if (s[i] == 'E' || s[i] == 'e')
    i++;
  powerSign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    /* skip white space */
    i++;
  for (val2 = 0; isdigit(s[i]); i++) {
    val2 = 10 * val2 + (s[i] - '0');
  }

  for (j = 0; j < val2; j++) {
    if (powerSign > 0) {
      power /= 10;
    } else {
      power *= 10;
    }
  }

  return sign * val / power;
}

int main() {
  char s[] = "123.456e-2";
  printf("The result %f\n", atof(s));
}