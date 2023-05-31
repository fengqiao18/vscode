#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int dp[N][N];
int main() {
  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();
  a = '?' + a, b = '?' + b;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = i;
  }
  for (int i = 1; i <= m; i++) {
    dp[0][i] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] != b[j]) {
        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
      } else {
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]) + 1);
      }
    }
  }
  cout << dp[n][m];
  return 0;
}