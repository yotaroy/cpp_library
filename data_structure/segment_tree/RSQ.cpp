#include <bits/stdc++.h>
using namespace std;

// Segment Tree
// RSQ (Range Sum Query)
template <typename T>
      struct RSQ {
        const T ZERO = 0;
        int num;
        vector<T> dat;
        RSQ(int n) : dat(n*4, ZERO) {
          int x = 1;
          while (n > x) {
            x *= 2;
          }
          num = x;
        }

        T at(int idx) {
          idx += num - 1;
          return dat[idx];
        }

        void update(int idx, T x) {
          idx += num - 1;
          dat[idx] = x;
          while (idx > 0) {
            idx = (idx - 1) / 2;
            dat[idx] = dat[idx * 2 + 1] + dat[idx * 2 + 2];
          }
        }

        // get sum in [a, b)
        T query(int a, int b) {
          return query_sub(a, b, 0, 0, num);
        }

        T query_sub(int a, int b, int k, int l, int r) {
          if (r <= a || b <= l) {
            return ZERO;
          } else if (a <= l && r <= b) {
            return dat[k];
    } else {
      T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return vl + vr;
    }
  }
};


int main() {
  const int n = 10;
  RSQ<int> seg(n);
  int arr[n] = {6, 3, 2, 5, 8, 4, 9, 1, 7, 0};
  for (int i=0; i<n; i++) seg.update(i, arr[i]);

  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      cout << i << " " << j << " " << seg.query(i, j) << endl;
    }
  }

  seg.update(5, 0);
  cout << "update:" << endl;
  seg.update(7, 3);
  cout << "update:" << endl;

  for (int i=0; i<n; i++) {
    for (int j=i+1; j<n; j++) {
      cout << i << " " << j << " " << seg.query(i, j) << endl;
    }
  }

}