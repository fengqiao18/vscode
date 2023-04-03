#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node {
  int x, y, w;
} e[N];
int fa[N];
int n , m;
int sum, cnt;
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); };
inline int unionn(int x, int y) { return x = find(x), y = find(y), fa[x] = x != y ? y : fa[x]; }
inline bool cmp(node x, node y) { return x.w < y.w; }
inline void kruskal() {
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  sort(e + 1, e + 1 + m, cmp);
  for (int i = 1; i <= m; i++) {
    int x = find(e[i].x), y = find(e[i].y);
    if (x == y) {
      continue;
    }
    sum = sum + e[i].w;
    unionn(x, y);
    cnt++;
    if (cnt == n - 1) {
      return;
    }
  }
  return;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> e[i].x >> e[i].y >> e[i].w;
  }
  kruskal();
  if (cnt < n - 1) {
    cout << "orz";
  } else {
    cout << sum;
  }
  return 0;
}