#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int dp[N], val[N], w[N];
int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    cin >> val[i] >> w[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = w[i]; j <= m; j++) {
      dp[j] = max(dp[j], dp[j - w[i]] + val[i]);
    }
  }
  cout << dp[m];
  return 0;
}