#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Edge {
  int w, u, v;
} e[N];
int fa[N], n, m, cnt, sum, tot, w[N];
int find(int x) {
  if (fa[x] == x)
    return fa[x];
  return fa[x] = find(fa[x]);
}
void unionn(int x, int y) {
  x = find(x), y = find(y);
  if (x != y)
    fa[x] = y;
  return;
}
bool cmp(Edge x, Edge y) {
  return x.w < y.w;
}
void kruskal() {
  for (int i = 1; i <= n + 1; i++)
    fa[i] = i;
  sort(e + 1, e + 1 + cnt, cmp);
  for (int i = 1; i <= cnt; i++) {
    int x = find(e[i].u), y = find(e[i].v);
    if (x != y) {
      unionn(x, y);
      sum += e[i].w;
      tot++;
      if (tot == n)
        return;
    }
  }
  return;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> w[i];
  for (int i = 1; i <= n; i++)
    for (int j = 1, x; j <= n; j++) {
      cin >> x;
      e[++cnt].w = x;
      e[cnt].u = i;
      e[cnt].v = j;
    }
  for (int i = 1; i <= n; i++) {
    e[++cnt].u = i;
    e[cnt].v = n + 1;
    e[cnt].w = w[i];
  }
  kruskal();
  cout << sum;
  return 0;
}