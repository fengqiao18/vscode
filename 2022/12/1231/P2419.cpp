#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int g[N][N];
int main() {
  int n, m;
  cin >> n >> m;
  int x, y;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    g[x][y] = 1;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        g[i][j] |= (g[i][k] && g[k][j]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        continue;
      } else if (g[i][j] || g[j][i]) {
        cnt++;
      }
    }
    ans += cnt == n - 1;
  }
  cout << ans;
  return 0;
}
