#include <stdio.h>

void insert_sort(int arr[], int len);

void insert_sort(int arr[], int len) {
  int i;
  int j;
  int key;
  for (i = 1; i < len; i++) {
    j = i - 1;
    key = arr[i];
    while ((j >= 0) && key < arr[j]) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main() {
  int arr[] = {1, 10, 8, 4, 6};
  insert_sort(arr, 5);
  int i;
  for (i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
}