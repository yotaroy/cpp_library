#include <iostream>

template <typename T>
void insertion_sort(int size, T *arr) {
  for (int i = 0; i < size; i++) {
    T v = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > v) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = v;
  }
}

int main() {
  int n = 10;
  int arr[] = {8, 2, 5, 3, 1, 6, 9, 10, 4, 7};

  insertion_sort(n, arr);

  for (auto x: arr) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}
