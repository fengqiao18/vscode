#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int dp[N][N][2];
int x[N], w[N], sum[N];
int main() {
  int n , c;
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> w[i];
    sum[i] = sum[i - 1] + w[i];
  }
  for(int i = 1 ; i <= n ; i++){
    dp[i][i][0] = dp[i][i][1] = abs(x[c] - x[i]) * (sum[n] - w[c]);
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      dp[i][j][0] = min(dp[i + 1][j][0] + (x[i + 1] - x[i]) * (sum[i] + sum[n] - sum[j]), dp[i + 1][j][1] + (x[j] - x[i]) * (sum[i] + sum[n] - sum[j]));
      dp[i][j][1] = min(dp[i][j - 1][0] + (x[j] - x[i]) * (sum[i - 1] + sum[n] - sum[j - 1]), dp[i][j - 1][1] + (x[j] - x[j - 1]) * (sum[i - 1] + sum[n] - sum[j - 1]));
    }
  }
  cout << min(dp[1][n][0], dp[1][n][1]);
  return 0;
}