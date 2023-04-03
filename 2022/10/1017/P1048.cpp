#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m;
int w[N], v[N], dp[N][N];
int dfs(int x, int y) {
  if (x <= 0 || y <= 0) {
    return 0;
  }
  if (dp[x][y] != -1) {
    return dp[x][y];
  }
  if (y >= w[x]) {
    return dp[x][y] = max(dfs(x - 1, y - w[x]) + v[x], dfs(x - 1, y));
  }
  return dp[x][y] = dfs(x - 1, y);
}
int main() {
  cin >> m >> n;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = -1;
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
  }
  cout << dfs(n, m);
  return 0;
}