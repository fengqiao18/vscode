#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int fa[N], n, m, k, cnt, sum;
struct node {
  int x, y, w;
} e[N];
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); };
inline int unionn(int x, int y) { return x = find(x), y = find(y), fa[x] = x != y ? y : fa[x]; }
inline bool cmp(node x, node y) { return x.w < y.w; }
inline void kruskal() {
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  sort(e + 1, e + m + 1, cmp);
  for (int i = 1; i <= m; i++) {
    int x = find(e[i].x), y = find(e[i].y);
    if (x == y) {
      continue;
    }
    cnt++;
    sum += e[i].w;
    unionn(x, y);
    if (cnt == n - k) {
      return;
    }
  }
  return;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> e[i].x >> e[i].y >> e[i].w;
  }
  kruskal();
  if (cnt == n - k) {
    cout << sum;
  } else {
    cout << "No Answer";
  }
  return 0;
}