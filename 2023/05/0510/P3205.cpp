#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int p = 19650827;
int h[N], dp[N][N][2];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    dp[i][i][0] = 1;
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      if (h[i] < h[i + 1]) {
        dp[i][j][0] = (dp[i][j][0] + dp[i + 1][j][0]) % p;
      }
      if (h[i] < h[j]) {
        dp[i][j][0] = (dp[i][j][0] + dp[i + 1][j][1]) % p;
      }
      if (h[j] > h[j - 1]) {
        dp[i][j][1] = (dp[i][j][1] + dp[i][j - 1][1]) % p;
      }
      if (h[j] > h[i]) {
        dp[i][j][1] = (dp[i][j][1] + dp[i][j - 1][0]) % p;
      }
    }
  }
  cout << (dp[1][n][1] + dp[1][n][0]) % p;
  return 0;
}