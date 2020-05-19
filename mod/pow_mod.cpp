#include <bits/stdc++.h>
using namespace std;

// a^b mod MOD
template <typename T>
T pow_mod(T a, T b, T MOD){
  if (b==0) return 1;
  T x = pow_mod(a, b/2, MOD);
  x *= x;
  if (b%2 == 1) x *= a;
  return x % MOD;
}


using ll = long long;
const ll mod = ll(1e9) + 7;
int main(){
  ll a = 2, b = 10;
  cout << pow_mod(a, b, mod) << endl;;
  b = 1000000;
  cout << pow_mod(a, b, mod) << endl;;
}