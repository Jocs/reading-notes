#include <stdio.h>

int binSearch(int x, int arr[], int n) {
  int low = 0;
  int high = n - 1;
  int mid = (low + high) / 2;

  while (low <= high && arr[mid] != x) {
    if (x < arr[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
    mid = (low + high) / 2;
  }

  if (arr[mid] == x) {
    return mid;
  }

  return -1;
}

int main() {
  int arr[100];
  int i;
  for (i = 0; i < 100; i++) {
    arr[i] = i;
  }

  int result = binSearch(50, arr, 100);
  printf("The result is: %d\n", result);
}