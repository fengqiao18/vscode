#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int dx[] = {0, 0, 0, 1, -1};
const int dy[] = {0, 1, -1, 0, 0};
int n, m, ans = -1e9;
int a[N][N], s[N][N];
int dfs(int x, int y) {
  if (s[x][y] != 0) {
    return s[x][y];
  }
  s[x][y] = 1;
  for (int i = 1; i <= 4; i++) {
    int xx = dx[i] + x, yy = dy[i] + y;
    if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[x][y] > a[xx][yy]) {
      s[x][y] = max(s[x][y], dfs(xx, yy) + 1);
    }
  }
  return s[x][y];
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ans = max(ans, dfs(i, j));
    }
  }
  cout << ans;
  return 0;
}