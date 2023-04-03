#include <bits/stdc++.h>
using namespace std;
const int N = 250000;
int s, p, fa[N], cnt, tot;
double sum;
struct node {
  int x, y;
  double w;
} e[N];
struct point {
  double x, y;
} a[N];
inline double f(double x) { return x * x; }
inline bool cmp(node x, node y) { return x.w < y.w; }
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); };
inline double getdis(int x, int y) { return sqrt(f(a[x].x - a[y].x) + f(a[x].y - a[y].y)); }
inline int unionn(int x, int y) { return x = find(x), y = find(y), fa[x] = x != y ? y : fa[x]; }
void kruskal() {
  sort(e + 1, e + 1 + tot, cmp);
  for (int i = 1; i <= p; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= tot; i++) {
    int x = find(e[i].x), y = find(e[i].y);
    if (x == y) {
      continue;
    }
    unionn(x, y);
    cnt++;
    if (cnt == p - s) {
      cout << fixed << setprecision(2) << e[i].w;
      return;
    }
  }
  return;
}
int main() {
  cin >> s >> p;
  for (int i = 1; i <= p; i++) {
    cin >> a[i].x >> a[i].y;
  }
  for (int i = 1; i <= p; i++) {
    for (int j = i + 1; j <= p; j++) {
      tot++;
      e[tot].x = i;
      e[tot].y = j;
      e[tot].w = getdis(i, j);
    }
  }
  kruskal();
  return 0;
}