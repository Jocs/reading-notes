#include <stdio.h>

int main(void)
{
  int score;
  printf("Please enter your score:\n");
  scanf("%d", &score);
  if (score < 0 || score > 100) {
    printf("error: you entered wrong score: %d", score);
    return 0;
  }
  int g = score / 10;
  switch (g) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      printf("Your score is F\n");
      break;
    case 6:
      printf("Your score is D\n");
      break;
    case 7:
      printf("Your score is C\n");
      break;
    case 8:
      printf("Your score is B\n");
      break;
    case 9:
    case 10:
      printf("Your score is A\n");
      break;
  }
  return 0;
}