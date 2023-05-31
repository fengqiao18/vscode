#include <bits/stdc++.h>
using namespace std;
const int N = 4005;
int n, b;
int dp[N][N][2], w[N];
void helper() {
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= b; j++) {
      if (i >= j) {
        dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
        if (j >= 1){
          dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1] + w[i]);
        }
      }
    }
  }
  return;
}
int main() {
  cin >> n >> b;
  memset(dp, -0x3f, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  dp[1][0][0] = dp[1][1][1] = 0;
  helper();
  int ans = dp[n][b][0];
  memset(dp, -0x3f, sizeof(dp));
  dp[1][0][0] = 0;
  dp[1][1][1] = w[1];
  helper();
  cout << max(ans, dp[n][b][1]);
  return 0;
}