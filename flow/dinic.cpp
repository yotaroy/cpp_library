#include <bits/stdc++.h>
using namespace std;


template <typename T>
struct Dinic {
  struct edge {
    int to;
    T cap;
    int rev;
    edge() {}
    edge(int to, T cap, int rev): to(to), cap(cap), rev(rev) {}
  };

  vector<vector<edge>> G;
  vector<int> level, iter;

  Dinic() {}
  Dinic(int max_v): G(max_v), level(max_v), iter(max_v){}

  void add_edge(int from, int to, T cap, bool directed=false) {
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, directed ? 0 : cap, G[from].size() - 1));
  }

  void bfs(int s) {
    fill(level.begin(), level.end(), -1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (int i = 0; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          que.push(e.to);
        }
      }
    }
  }

  T dfs(int v, int t, T f) {
    if (v == t) return f;
    for (int &i = iter[v]; i < G[v].size(); i++) {
      edge &e = G[v][i];
      if (e.cap > 0 && level[v] < level[e.to]) {
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
      bfs(s);
      if (level[t] < 0) return flow;
      fill(iter.begin(), iter.end(), 0);
      T f;
      while ((f = dfs(s, t, numeric_limits<T>::max())) > 0) {
        flow += f;
      }
    }
  }

};

// test
void ABC010_D() {
  int n, g, e;
  cin >> n >> g >> e;
  Dinic<int> dinic(n+1);

  for (int i = 0; i < g; i++) {
    int p;
    cin >> p;
    dinic.add_edge(p, n, 1);
  }

  for (int i = 0; i < e; i++) {
    int a, b;
    cin >> a >> b;
    dinic.add_edge(a, b, 1);
  }

  cout << dinic.max_flow(0, n) << endl;
}

int main() {
  ABC010_D();
  return 0;
}
