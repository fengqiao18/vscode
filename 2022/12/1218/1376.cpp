#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int maxi = -1e9;
int g[N][N];
int n, m;
inline void floyd() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
  return;
}
int main() {
  memset(g, 0x3f, sizeof(g));
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    g[y][x] = g[x][y] = min(g[x][y], w);
  }
  for (int i = 1; i <= n; i++) {
    g[i][i] = 0;
  }
  floyd();
  for (int i = 1; i <= n; i++) {
    maxi = max(maxi, g[1][i]);
  }
  if (maxi == 0x3f3f3f3f) {
    cout << -1;
  } else {
    cout << maxi;
  }
  return 0;
}