#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct node {
  int x, y, w;
} a[N];
int n, m, k, fa[N];
bool cmp(node x, node y) {
  return x.w > y.w;
}
int find(int x) {
  if (x != fa[x])
    fa[x] = find(fa[x]);
  return fa[x];
}
void kruskal() {
  int i = 1, cnt = 0, tot = 0;
  while (i <= m) {
    int x = find(a[i].x);
    int y = find(a[i].y);
    if (x != y) {
      fa[x] = y;
      tot += a[i].w;
      cnt++;
    }
    if (cnt == k)
      break;
    i++;
  }
  printf("%d", tot);
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++){
    cin >> a[i].x >> a[i].y >> a[i].w;
  }
  for (int i = 1; i <= n; i++)
    fa[i] = i;
  sort(a + 1, a + 1 + m, cmp);
  kruskal();
  return 0;
}
