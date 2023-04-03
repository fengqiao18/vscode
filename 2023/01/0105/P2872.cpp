#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct point {
  double x, y;
};
struct node {
  int u, v;
  double w;
};
node e[N];
point a[N];
int fa[N];
double sum;
int n, m, cnt;
inline double f(double x) { return x * x; }
inline bool cmp(node x, node y) { return x.w < y.w; }
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); };
inline double dis(int i, int j) { return sqrt(f(a[i].x - a[j].x) + f(a[i].y - a[j].y)); }
inline int unionn(int x, int y) { return x = find(x), y = find(y), fa[x] = x != y ? y : fa[x]; }
inline void kruskal() {
  sort(e + 1, e + 1 + cnt, cmp);
  for (int i = 1; i <= cnt; i++) {
    int x = find(e[i].u), y = find(e[i].v);
    if (x == y) {
      continue;
    }
    sum = sum + e[i].w;
    unionn(x, y);
  }
  return;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      e[++cnt].w = dis(i, j);
      e[cnt].u = i, e[cnt].v = j;
    }
  }
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    unionn(x, y);
  }
  kruskal();
  cout << fixed << setprecision(2) << sum;
  return 0;
}