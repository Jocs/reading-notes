#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

void initialize_number_generator(void);
int new_secret_number(void);
void read_guesses(int secret_number);

int main(void)
{
  int secret_number;
  char command;
  initialize_number_generator();
  do {
    printf("A number has been generated between 1 and %d\n\n", MAX_NUMBER);
    secret_number = new_secret_number();
    read_guesses(secret_number);
    printf("Try Again(Y/N): ");
    scanf(" %c", &command);
    printf("\n");
  } while (command == 'y' || command == 'Y');
  return 0;
}

void initialize_number_generator(void)
{
  srand((unsigned) time(NULL));
}

int new_secret_number(void)
{
  return rand() % MAX_NUMBER + 1;
}

void read_guesses(int secret_number)
{
  int number, count = 0;
  for (;;) {
    printf("Enter your guess:");
    scanf("%d", &number);
    count++;
    if (number == secret_number) {
      printf("Good, You guess the number in %d steps\n", count);
      return;
    } else if (number < secret_number) {
      printf("Too low guess again!\n");
    } else {
      printf("Too high guess again!\n");
    }
  }
}
