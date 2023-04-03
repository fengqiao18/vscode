#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
struct node {
  int p, u, v, w;
};
node e[N];
int fa[N];
int n, m, ans = 0;
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); };
inline int unionn(int x, int y) { return x = find(x), y = find(y), fa[x] = x != y ? y : fa[x]; }
inline bool cmp(node x, node y) { return x.w < y.w; }
inline void kruskal() {
  sort(e + 1, e + 1 + m, cmp);
  for (int i = 1; i <= m; i++) {
    int x = find(e[i].u), y = find(e[i].v);
    if (x == y) {
      continue;
    }
    ans += e[i].w;
    unionn(x, y);
  }
  return;
}
int main() {
  int p;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> e[i].p >> e[i].u >> e[i].v >> e[i].w;
    if (e[i].p == 1) {
      unionn(e[i].u, e[i].v);
      ans = ans + e[i].w;
    }
  }
  kruskal();
  cout << ans;
  return 0;
}