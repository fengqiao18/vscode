#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 5;
const int M = 1e7 + 5;
int dp[M], w[N], val[N];
signed main() {
  int sum, n, m;
  cin >> sum >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> w[i] >> val[i];
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= m; i++) {
      for (int j = w[i]; j <= sum; j++) {
        dp[j] = max(dp[j], dp[j - w[i]] + val[i]);
      }
    }
    sum += dp[sum];
  }
  cout << sum;
  return 0;
}