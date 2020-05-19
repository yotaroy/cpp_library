#include <iostream>
#include <algorithm>
#include <random>

template <typename T>
void display_arr(int size, T *arr);

template <typename T>
void quick_sort(int left, int right, T *arr) {
  if (right - left <= 1) return;

  int pivot = arr[right - 1];

  int idx = left;

  for (int i = left; i < right - 1; i++) {
    if (arr[i] <= pivot) {
      std::swap(arr[i], arr[idx]);
      idx++;
    }
  }

  std::swap(arr[idx], arr[right - 1]);
  idx++;

  quick_sort(left, idx - 1, arr);
  quick_sort(idx, right, arr);
}

template <typename T>
void display_arr(int size, T *arr) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i];

    if (i < size - 1) std::cout << " ";
    else std::cout << std::endl;
  }
}


int main() {
  const int n = 1000;
  int arr[n];
  for (int i = 0; i < n; i++) arr[i] = i;

  std::mt19937_64 get_rand_mt;
  std::shuffle(arr, arr+n, get_rand_mt);

  display_arr(n, arr);

  quick_sort(0, n, arr);

  display_arr(n, arr);

  return 0;
}
