#include <bits/stdc++.h>
using namespace std;
namespace lyt {
const int N = 1e5 + 5;
const int M = 1e4 + 5;
int g[M], to[N];
int nxp[N], d[N];
int tmp[M], ans[M];
bool vis[M];
int n, m, cp = 1, p;
inline void add(int x, int y, int k) {
  d[cp] = k;
  to[cp] = y;
  nxp[cp] = g[x];
  g[x] = cp;
  cp++;
  return;
}
inline void dfs(int cur) {
  if (vis[cur]) {
    return;
  }
  vis[cur] = 1;
  for (int i = g[cur]; i >= 1; i = nxp[i]) {
    dfs(to[i]);
  }
  tmp[p++] = cur;
  return;
}
inline void check() {
  for (int i = 1; i <= n; i++) {
    dfs(i);
  }
  for (int i = 0; i < n; i++) {
    int x = tmp[i];
    ans[x] = 0;
    for (int j = g[x]; j >= 1; j = nxp[j]) {
      int y = to[j];
      if (ans[x] < ans[y] + d[j]) {
        ans[x] = ans[y] + d[j];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  return;
}
inline void work() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, k;
    cin >> x >> y >> k;
    add(x, y, k);
  }
  check();
  return;
}
}  // namespace lyt
int main() {
  lyt::work();
  return 0;
}