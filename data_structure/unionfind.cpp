#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  int num;
  vector<int> par, rank;
  UnionFind() {}
  UnionFind(int n) : num(n), par(n, 1), rank(n, 0) { iota(par.begin() ,par.end(), 0); }
  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
  }
  void unite (int x, int y) {
    x = find(x);
    y = find(y);
    if (x==y) return;
    if (rank[x] < rank[y]) swap(x, y);
    rank[x] += rank[y];
    par[y] = x;
    num--;
  }
  int size(int x) {
    return rank[find(x)];
  }
  int count() const {
    return num;
  }
};


int ABC126_E () {
  int n, m;
  cin >> n >> m;
  UnionFind uni(n);
  for (int i=0; i<m; i++){
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    uni.unite(x, y);
  }
  cout << uni.count() << endl;
  return 0;
}

int main(){
  ABC126_E();

  return 0;
}