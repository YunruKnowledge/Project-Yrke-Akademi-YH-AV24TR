#include <stdio.h>

int main() {
  int arr[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      scanf("%i", &arr[row][col]);
    }
  }

  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      (void)printf("\t%i ", arr[row][col]);
    }
    (void)printf("\n");
  }

  return 0;
}