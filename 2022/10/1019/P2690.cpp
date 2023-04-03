#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, w;
int a[N], dp[N][3][35];
int dfs(int i, int j, int k) {
  if (i > n) {
    return 0;
  }
  if (dp[i][j][k] != -1) {
    return dp[i][j][k];
  }
  int tmp1 = 0, tmp2 = 0;
  if (k < w && a[i] != j) {
    tmp1 = dfs(i + 1, -1 * j + 3, k + 1) + 1;
  }
  tmp2 = dfs(i + 1, j, k) + (j == a[i] ? 1 : 0);
  return dp[i][j][k] = max(tmp1, tmp2);
}
int main() {
  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << dfs(1, 1, 0);
  return 0;
}