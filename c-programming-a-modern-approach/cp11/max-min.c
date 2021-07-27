#include <stdio.h>

#define LEN 10

void max_min(int b[], int n, int *max, int *min);
void lagest_num(int b[], int n, int *first_largest, int *second_largest);

void max_min(int b[], int n, int *max, int *min)
{
  int i;
  *max = b[0];
  *min = b[0];
  for (i = 0; i < n; i++) {
    if (b[i] > *max) *max = b[i];
    if (b[i] < *min) *min = b[i];
  }
}

void lagest_num(int b[], int n, int *first_largest, int *second_largest)
{
  int i;
  *first_largest = b[0] > b[1] ? b[0] : b[1];
  *second_largest = b[0] > b[1] ? b[1] : b[0];
  for (i = 2; i < n; i++) {
    if (b[i] > *first_largest) {
      *second_largest = *first_largest;
      *first_largest = b[i];
    } else if (b[i] > *second_largest) {
      *second_largest = b[i];
    }
  }
}

int main() {
  int i;
  int c[LEN];
  int large, small;
  int first, second;
  for (i = 0; i < LEN; i++)
  {
    scanf("%d", &c[i]);
  }
  max_min(c, LEN, &large, &small);
  lagest_num(c, LEN, &first, &second);
  printf("large number is: %d\n", large);
  printf("small number is: %d\n", small);

  printf("first laget num: %d\n", first);
  printf("second large num: %d\n", second);
}