#include <iostream>
#include <algorithm>
#include <random>
#include <limits>

template <typename T>
void display_arr(int size, T *arr);

template <typename T>
int merge_sort(int left, int right, T *arr) {
  if (right - left <= 1) return 1;

  int mid = (left + right) / 2;
  int cnt = 1;
  cnt += merge_sort(left, mid, arr);
  cnt += merge_sort(mid, right, arr);

  T *l = new T[mid - left + 1];
  T *r = new T[right - mid + 1];
  for (int i = 0; i < mid - left; i++) l[i] = arr[left + i];
  for (int i = 0; i < right - mid; i++) r[i] = arr[mid + i];
  l[mid - left] = std::numeric_limits<T>::max();
  r[right - mid] = std::numeric_limits<T>::max();

  int l_idx = 0, r_idx = 0;

  for (int i = left; i < right; i++) {
    if (l[l_idx] <= r[r_idx]) {
      arr[i] = l[l_idx];
      l_idx++;
    }
    else {
      arr[i] = r[r_idx];
      r_idx++;
    }
  }

  delete[] l;
  delete[] r;

  return cnt;
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

  int cnt = merge_sort(0, n, arr);

  display_arr(n, arr);

  std::cout << cnt << std::endl;

  return 0;
}
