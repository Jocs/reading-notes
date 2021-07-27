#include <stdio.h>

int main(void)
{
  int gs1_prefix, group_identifier, publisher, item_number, check;
  printf("Enter ISBN:\n");
  scanf("%d-%d-%d-%d-%d", &gs1_prefix, &group_identifier, &publisher, &item_number, &check);

  printf("GS1 PREFIX: %d\n", gs1_prefix);
  printf("Groud identifier: %d\n", group_identifier);
  printf("Publisher: %d\n", publisher);
  printf("Item number: %d\n", item_number);
  printf("Check: %d\n", check);
  return 0;
}