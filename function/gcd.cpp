#include <bits/stdc++.h>
using namespace std;

// greatest common divisor
template <typename T>
T gcd(T a, T b) {
  if (a < b) swap(a, b);
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

// least common multiple
template <typename T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}

int main(){
  for (int i = 13; i < 20; i+=3) {
    for (int j = 23; j < 40; j+=3) {
      cout << "i = " << i << ", j = " << j << ", gcd = " << gcd(i, j) << ", lcm = " << lcm(i, j) << endl;
    }
  }
}
