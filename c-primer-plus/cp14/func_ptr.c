#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#define LEN 81

char showmenu(void);
void eatline(void);
void show(void(*fp)(char *), char *str);
void ToUpper(char *str);
void ToLower(char *str);
void Transpose(char *str);
void Dummy(char *str);

int main(void) {
  char line[LEN], copy[LEN];
  char choose;
  void (*pfun)(char *);
  puts("Enter a string you want to stransfer.");
  while (s_get(line, LEN) != NULL && line[0] != '\0') {
    while ((choose = showmenu()) != 'q') {
      switch (choose) {
        case 'u':
          pfun = ToUpper;
          break;
        case 'l':
          pfun = ToLower;
          break;
        case 't':
          pfun = Transpose;
          break;
        case 'd':
          pfun = Dummy;
          break;   
      }
      strcpy(copy, line);
      show(pfun, copy);
    }
    puts("Enter a string, empty to quit.");
  }
  puts("Bye.");

  return 0;
}

char showmenu(void) {
  puts("Enter your choose?");
  puts("u) uppercase.    l) lowercase");
  puts("t) transpose     d) do nothing");
  puts("q) quit program.");

  char ans = getchar();
  ans = tolower(ans);
  eatline();
  while (strchr("ultdq", ans) == NULL) {
    puts("Please enter u, l, t, d, q.");
    ans = tolower(getchar());
    eatline();
  }

  return ans;
}

void eatline(void) {
  while (getchar() != '\n')
    continue;
}

void show(void(*fp)(char *), char *str) {
  (*fp)(str);
  puts(str);
}
void ToUpper(char *str) {
  while (*str) {
    *str = toupper(*str);
    str++;
  }
}
void ToLower(char *str) {
  while (*str) {
    *str = tolower(*str);
    str++;
  }
}
void Transpose(char *str) {
  while (*str) {
    if (islower(*str)) {
      *str = toupper(*str);
    } else {
      *str = tolower(*str);
    }
    str++;
  }
}
void Dummy(char *str) {
  // Do nothing.
}
