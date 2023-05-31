#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int a[N], sum[N];
int dp[N][N], f[N][N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[n + i] = a[i];
  }
  memset(f, 0x3f, sizeof(f));
  int n_ = n * 2 - 1;
  for (int i = 1; i <= n_; i++) {
    sum[i] = sum[i - 1] + a[i];
    dp[i][i] = f[i][i] = 0;
  }
  for (int len = 2; len <= n_; len++) {
    for (int i = 1; i + len - 1 <= n_; i++) {
      int j = i + len - 1;
      for (int k = i; k <= j - 1; k++) {
        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1]);
      }
    }
  }
  int maxi = -1e9, mini = 1e9;
  for (int i = 1; i <= n; i++) {
    maxi = max(maxi, dp[i][n + i - 1]);
    mini = min(mini, f[i][n + i - 1]);
  }
  cout << mini << "\n" << maxi;
  return 0;
}