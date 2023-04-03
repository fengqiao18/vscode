#include <bits/stdc++.h>
using namespace std;
int w[3], val[3], dp[10205];
int main() {
  int c, d, n, m, k;
  cin >> c >> d >> n >> m >> k;
  w[1] = n, w[2] = 1, val[1] = c, val[2] = d;
  for (int i = 1; i <= 10200; i++) {
    dp[i] = 1e9;
  }
  dp[0] = 0;
  for (int i = 1; i <= 2; i++) {
    for (int j = w[i]; j <= 10200; j++) {
      dp[j] = min(dp[j], dp[j - w[i]] + val[i]);
    }
  }
  int ans = 1e9;
  for (int i = max(0, n * m - k); i <= 10200; i++) {
    ans = min(ans, dp[i]);
  }
  cout << ans;
  return 0;
}