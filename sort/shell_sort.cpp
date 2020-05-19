#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

template <typename T>
void display_arr(int size, T *arr);

template <typename T>
void insertion_sort(int size, T *arr, int g) {
  for (int i = g; i < size; i++) {
    int v = arr[i];
    int j = i - g;
    while (j >= 0 && arr[j] > v) {
      arr[j + g] = arr[j];
      j -= g;
    }
    arr[j + g] = v;
  }
}

template <typename T>
void shell_sort(int size, T *arr) {
  std::vector<int> G;
  for (int i = 1; i < size; i = 3 * i + 1) {
    G.push_back(i);
  }

  for (int i = G.size() - 1; i >= 0; i--) {
    std::cout << G[i] << std::endl;

    insertion_sort(size, arr, G[i]);

    display_arr(size, arr);
  }
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
  const int n = 100;
  int arr[n];
  for (int i = 0; i < n; i++) arr[i] = i;

  std::mt19937_64 get_rand_mt;
  std::shuffle(arr, arr+n, get_rand_mt);

  display_arr(n, arr);

  shell_sort(n, arr);

  display_arr(n, arr);

  return 0;
}
