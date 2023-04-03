#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int p = 998244353;
int dp[N][N * 2][2];
int main() {
  int n, k;
  cin >> n >> k;
  dp[1][2][0] = dp[1][3][1] = 2;
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= k + 1; j++) {
      dp[i][j][0] = (dp[i - 1][j][1] * 2LL + dp[i - 1][j][0] + dp[i - 1][j - 1][0]) % p;
      dp[i][j][1] = (dp[i - 1][j - 1][0] * 2LL + dp[i - 1][j][1] + dp[i - 1][j - 2][1]) % p;
    }
  }
  cout << (dp[n][k + 1][0] + dp[n][k + 1][1]) % p;
  return 0;
}