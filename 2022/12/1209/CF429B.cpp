#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int dp1[N][N], dp2[N][N], dp3[N][N], dp4[N][N], a[N][N];
int n, m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp1[i][j] = a[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      dp2[i][j] = a[i][j] + max(dp2[i + 1][j], dp2[i][j + 1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      dp4[i][j] = a[i][j] + max(dp4[i - 1][j], dp4[i][j + 1]);
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      dp3[i][j] = a[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);
    }
  }
  int ans = 0;
  for (int i = 2; i < n; i++) {
    for (int j = 2; j < m; j++) {
      ans = max(ans, dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j]);
      ans = max(ans, dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1]);
    }
  }
  cout << ans;
  return 0;
}