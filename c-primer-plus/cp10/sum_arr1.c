#include <stdio.h>
#define SIZE 10
int sum(int arr[], int n);

int main(void) {
  int marbles[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int total = sum(marbles, SIZE);

  printf("The total of marbles is %d\n", total);
  printf("The size of marble is %zd bytes\n", sizeof marbles);
}

int sum(int *arr, int n) {
  int total = 0;
  int i = 0;

  while (i++ < n) {
    total += *arr++;
  }

  printf("The size of arr is %zd bytes\n", sizeof arr);
  return total;
}