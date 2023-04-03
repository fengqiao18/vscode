#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
int a[N], d[N];
int dp[N][N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  memset(dp, 0x3f, sizeof(dp));
  int n, l, k;
  cin >> n >> l >> k;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  d[n + 1] = l;
  for (int i = 0; i <= k; i++) {
    dp[1][i] = 0;
  }
  for (int i = 2; i <= n + 1; i++) {
    for (int j = 0; j <= min(i - 1, k); j++) {
      for (int m = 0; m <= j; m++) {
        dp[i][j] = min(dp[i][j], dp[i - m - 1][j - m] + (d[i] - d[i - m - 1]) * a[i - m - 1]);
      }
    }
  }
  int mini = 1e18;
  for (int i = 0; i <= k; i++) {
    mini = min(mini, dp[n + 1][i]);
  }
  cout << mini;
  return 0;
}