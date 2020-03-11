#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;
struct mint{
  ll v;
  mint(ll a=0):v((a%mod+mod)%mod){}
  mint operator-() const {
    return mint(-v);
  }
  mint& operator+=(const mint a){
    if ((v += a.v) >= mod) v -= mod;
    return *this;
  }
  mint& operator-=(const mint a){
    if ((v += mod - a.v) >= mod) v -= mod;
    return *this;
  }
  mint& operator*=(const mint a){
    (v *= a.v) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  // v^t
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if(t&1) a *= *this;
    return a;
  }

  // for prime mod
  // Fermat's little theorem : a^(p-1) = 1 (mod p) when p is prime and a = 1 (mod p)
  mint inv() const {
    return pow(mod - 2);
  }
  mint& operator/=(const mint a){
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }

  // k < 10^6, n < 10^9
  static mint comb(ll n, int k){
    mint num(1), den(1);
    for(int i=0; i<k; i++){
      num *= mint(n-i);
      den *= mint(i+1);
    }
    return num / den;
  }
};

// for cout << 
ostream& operator<<(ostream& stream, const mint a){
  stream << a.v;
  return stream;
}

// example

void ex(){
  mint a = - 20;
  cout << a << endl;
  mint b(- 22);
  cout << b << endl;
  mint c{3};
  cout << c << endl;
  c = c.pow(3);
  cout << c << endl;
}

int ABC156_D(){
  ll n, a, b;
  cin >> n >> a >> b;

  mint ans(2), ca, cb;
  ans = ans.pow(n);
  ca = ca.comb(n, a);
  cb = cb.comb(n, b);
  ans = ans - 1 - ca - cb;
  cout << ans << endl;

  return 0;
}

int main(){
  ex();
  // ABC156_D();
  return 0;
}
