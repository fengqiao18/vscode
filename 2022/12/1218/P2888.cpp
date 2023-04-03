#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int g[N][N];
int n, m, t;
inline void floyd() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        g[i][j] = min(g[i][j], max(g[i][k], g[k][j]));
      }
    }
  }
  return;
}
int main() {
  cin >> n >> m >> t;
  memset(g, 0x3f, sizeof(g));
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    g[x][y] = min(g[x][y], w);
  }
  for (int i = 1; i <= n; i++) {
    g[i][i] = 0;
  }
  floyd();
  for (int i = 1; i <= t; i++) {
    int s, t;
    cin >> s >> t;
    if (g[s][t] < 0x3f3f3f3f) {
      cout << g[s][t];
    } else {
      cout << -1;
    }
    cout << endl;
  }
  return 0;
}