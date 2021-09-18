#include <stdio.h>

int main(void)
{
  int age;
  float assets;
  char pet[30];
  printf("Enter your age, assets, and favorite pet.\n");
  scanf("%d %f", &age, &assets);
  scanf("%s", pet);
  printf("age: %d, assets: %.2f, pet: %s\n", age, assets, pet);

  return 0;
}