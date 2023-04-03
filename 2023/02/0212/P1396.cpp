#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
struct node {
  int x, y, w;
};
node a[N];
int fa[N];
int n, m, s, t;
inline bool cmp(node x, node y) { return x.w < y.w; }
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void unioun(int x, int y) { x = find(x), y = find(y), fa[x] = y; }
inline int kruskal() {
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  sort(a + 1, a + m + 1, cmp);
  for (int i = 1; i <= m; i++) {
    int x = find(a[i].x), y = find(a[i].y);
    if (x == y) {
      continue;
    }
    unioun(x, y);
    if (find(s) == find(t)) {
      return a[i].w;
    }
  }
  return 0;
}
int main() {
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].x >> a[i].y >> a[i].w;
  }
  cout << kruskal();
  return 0;
}
