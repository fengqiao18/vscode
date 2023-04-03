#include <bits/stdc++.h>
using namespace std;
const int N = 405;
int w[N], v[N], f[N], dp[N][N];
int main() {
  int V, m, n;
  cin >> n >> V >> m;
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> w[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= w[i]; j--) {
      for (int k = V; k >= v[i]; k--) {
        dp[j][k] = max(dp[j][k], dp[j - w[i]][k - v[i]] + 1);
      }
    }
  }
  cout << dp[m][V];
  return 0;
}