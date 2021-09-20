#include <stdio.h>
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);

int main(void) {
  int choice;
  while ((choice = get_choice()) != 'q') {
    switch (choice) {
      case 'a': {
        printf("you choose A\n");
        break;
      }
        
      case 'b': {
        putchar('\a');
        break;
      }

      case 'c': {
        count();
        break;
      }

      default: {
        printf("Program error!\n");
        break;
      }
    }
  }

  printf("Bye!\n");

  return 0;
}

char get_choice(void) {
  int ch;
  printf("Enter the letter of your choice:\n");
  printf("a. advice         b. bell\n");
  printf("c. count          q. quit\n");
  ch = get_first();
  while ((ch < 'a' || ch > 'c') && ch != 'q') {
    printf("Please response with a, b, c, or q. and you enter %c.\n", ch);
    ch = get_first();
  }

  return ch;
}

char get_first(void) {
  char ch = getchar();

  while (getchar() != '\n')
    continue;

  return ch;
}

void count(void) {
  int i, num;
  printf("Please input a number\n");
  num = get_int();
  for (i = 1; i <= num; i++) {
    printf("%d ", i);
  }
  printf("\n");
}

int get_int(void) {
  int result;
  while (scanf("%d", &result) != 1) {
    while(getchar() != '\n')
      continue;
    printf("Please inter an integer\n");
  }

  while(getchar() != '\n')
    continue;

  return result;
}
