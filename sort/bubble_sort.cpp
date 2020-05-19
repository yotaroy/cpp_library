#include <iostream>

template <typename T>
int bubble_sort(int size, T *arr) {
  int sw = 0;
  bool flag = true;
  for (int i = 0; flag; i++) {
    flag = false;
    for (int j = size - 1; j >= i + 1; j--) {
      if (arr[j] < arr[j - 1]) {
        int tmp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = tmp;
        flag = true;
        sw++;
      }
    }
  }
  return sw;
}

int main() {
  int n = 10;
  int arr[] = {8, 2, 5, 3, 1, 6, 9, 10, 4, 7};

  int sw = bubble_sort(n, arr);

  for (auto x: arr) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  std::cout << "number of swaps = " << sw << std:: endl;

  return 0;
}
