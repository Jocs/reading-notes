#include<stdio.h>
#include<ctype.h>

int htoi(char *s) {
  int p = 0;
  while (*s++ != '\0') {
    if (isdigit(*s)) {
      p = p * 16 + (*s - '0');
    } else {
      switch (*s) {
        case 'a':
        case 'A':
          p = p * 16 + 10;
          break;
        case 'b':
        case 'B':
          p = p * 16 + 11;
          break;
        case 'c':
        case 'C':
          p = p * 16 + 12;
          break;
        case 'd':
        case 'D':
          p = p * 16 + 13;
          break;
        case 'e':
        case 'E':
          p = p * 16 + 14;
          break;
        case 'f':
        case 'F':
          p = p * 16 + 15;
          break;
      }
    }
  }

  return p;
}

int main() {
  char * hexNum = (char *) "0xff";
  int decimelNum = htoi(hexNum);
  printf("The decimel number of %s is %d\n", hexNum, decimelNum);
}
