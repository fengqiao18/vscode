#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int a[N], dp[N][N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i][i] = a[i];
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      for (int k = 1; k <= j; k++) {
        int t1 = abs(a[i] - a[k]);
        int t2 = abs(a[j] - a[k + 1]);
        if (i == k) {
          t1 = a[i];
        }
        dp[i][j] = max(dp[i][j], t1 * (k - i + 1) + dp[k + 1][j]);
        if (j == k + 1) {
          t2 = a[j];
        }
        dp[i][j] = max(dp[i][j], t2 * (k - j) + dp[i][k]);
      }
    }
  }
  cout << dp[1][n];
  return 0;
}