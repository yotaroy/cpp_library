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

// combination
struct combination{
  vector<mint> fact, ifact;
  combination(int n): fact(n+1), ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for(int i=1; i<=n; i++){
      fact[i] = fact[i-1] * i;
    }
    ifact[n] = fact[n].inv();
    for(int i=n; i >=1; i--){
      ifact[i-1] = ifact[i] * i;
    }
  }
  mint operator()(int n, int k){
    if(k < 0 || k > n) return 0;
    return fact[n] * ifact[k] * ifact[n-k];
  }
};

// example
int ABC156_E(){
  ll n, k;
  cin >> n >> k;

  combination c(n);
  mint ans(0);
  for(int i=0; i<=min(n, k); i++){
    ans += c(n, i) * c(n-1, i);
  }
  cout << ans << endl;

  return 0;
}

int main(){
  ABC156_E();

  return 0;
}