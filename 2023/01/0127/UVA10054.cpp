#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int maxi = 0;
int deg[N], fa[N], G[N][N];
struct edge {
  int from, to;
} a[1005];
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); };
inline void unnion(int x, int y) { x = find(x), y = find(y), fa[x] = y; }
inline void dfs(int cur) {
  for (int i = 1; i <= maxi; i++) {
    if (G[cur][i]) {
      G[cur][i]--;
      G[i][cur]--;
      dfs(i);
      cout << i << " " << cur << endl;
    }
  }
  return;
}
inline void helper() {
  memset(deg, 0, sizeof(deg));
  memset(G, 0, sizeof(G));
  for (int i = 1; i <= 50; i++) {
    fa[i] = i;
  }
  int n;
  maxi = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a[i].from = x, a[i].to = y;
    deg[x]++, deg[y]++;
    G[x][y]++, G[y][x]++;
    maxi = max(maxi, max(x, y));
    unnion(x, y);
  }
  bool flag = 1;
  for (int i = 1; i <= maxi; i++) {
    if (!deg[i]) {
      continue;
    }
    if (deg[i] % 2 == 1 || find(i) != find(maxi)) {
      cout << "some beads may be lost\n\n";
      return;
    }
  }
  for (int i = 1; i <= maxi; i++) {
    dfs(i);
  }
  cout << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << endl;
    helper();
  }
  return 0;
}
