#include <iostream>

template <typename T>
int selection_sort(int size, T *arr) {
  int sw = 0, min_idx;
  for (int i = 0; i < size - 1; i++) {
    min_idx = i;
    for (int j = i; j < size; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    int tmp = arr[i];
    arr[i] = arr[min_idx];
    arr[min_idx] = tmp;
    if (i != min_idx) sw++;
  }
  return sw;
}

int main() {
  int n = 10;
  int arr[] = {8, 2, 5, 3, 1, 6, 9, 10, 4, 7};

  int sw = selection_sort(n, arr);

  for (auto x: arr) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  std::cout << "number of swaps = " << sw << std:: endl;

  return 0;
}
