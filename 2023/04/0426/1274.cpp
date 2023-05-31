#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int sum[N];
int a[N], dp[N][N];
int main() {
  memset(dp, 0x3f, sizeof(dp));
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i][i] = 0;
    sum[i] = sum[i - 1] + a[i];
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
      }
    }
  }
  cout << dp[1][n];
  return 0;
}