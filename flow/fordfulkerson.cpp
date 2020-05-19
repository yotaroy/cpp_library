#include <bits/stdc++.h>
using namespace std;


template <typename T>
struct FordFulkerson {
  struct edge {
    int to;
    T cap;
    int rev;
    edge() {}
    edge(int to, T cap, int rev): to(to), cap(cap), rev(rev) {}
  };

  vector<vector<edge>> G;
  vector<int> used;

  FordFulkerson() {}
  FordFulkerson(int max_v): G(max_v), used(max_v) {}

  void add_edge(int from, int to, T cap, bool directed=false) {
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, directed ? 0 : cap, G[from].size() - 1));
  }

  T dfs(int v, int t, T f) {
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
      edge &e = G[v][i];
      if (!used[e.to] && e.cap > 0) {
        T d = dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  T max_flow(int s, int t) {
    T flow = 0;
    while (true) {
      fill(used.begin(), used.end(), 0);
      T f = dfs(s, t, numeric_limits<T>::max());
      if (f == 0) return flow;
      flow += f;
    }
  }
};

// test
void ABC010_D() {
  int n, g, e;
  cin >> n >> g >> e;
  FordFulkerson<int> ford_fulkerson(n+1);

  for (int i = 0; i < g; i++) {
    int p;
    cin >> p;
    ford_fulkerson.add_edge(p, n, 1);
  }

  for (int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    ford_fulkerson.add_edge(a, b, 1);
  }

  cout << ford_fulkerson.max_flow(0, n) << endl;
}

int main() {
  ABC010_D();
  return 0;
}
