#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int p = 1e6 + 7;
int n, m;
int a[N], dp[N][N];
int main() {
  cin >> n >> m;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i][0] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= min(a[i], j); k++) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % p;
      }
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}