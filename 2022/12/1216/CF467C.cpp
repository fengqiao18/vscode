#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
long long sum[N], dp[N][N];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    sum[i] = sum[i - 1] + x;
  }
  dp[1][1] = sum[1];
  for (int i = m; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + (sum[i] - sum[i - m]));
    }
  }
  cout << dp[n][k];
  return 0;
}