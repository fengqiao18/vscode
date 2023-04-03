#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node {
  int u, v, w;
} e[N];
int fa[N], n, m, cnt, sum, tot, w[N];
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); };
inline int unionn(int x, int y) { return x = find(x), y = find(y), fa[x] = x != y ? y : fa[x]; }
inline bool cmp(node x, node y) { return x.w < y.w; }
void kruskal() {
  for (int i = 1; i <= n + 1; i++) {
    fa[i] = i;
  }
  sort(e + 1, e + 1 + cnt, cmp);
  for (int i = 1; i <= cnt; i++) {
    int x = find(e[i].u), y = find(e[i].v);
    if (x != y) {
      unionn(x, y);
      sum += e[i].w;
      tot++;
      if (tot == n) {
        return;
      }
    }
  }
  return;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1, x; j <= n; j++) {
      cin >> x;
      cnt++;
      e[cnt].u = i, e[cnt].v = j, e[cnt].w = x;
    }
  }
  for (int i = 1; i <= n; i++) {
    cnt++;
    e[cnt].u = i, e[cnt].v = n + 1, e[cnt].w = w[i];
  }
  kruskal();
  cout << sum;
  return 0;
}