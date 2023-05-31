#include <bits/stdc++.h>
using namespace std;
const int N = 305;
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
      for (int k = i; k < j; k++) {
        if (dp[i][k] == dp[k + 1][j]) {
          dp[i][j] = max(dp[i][j], dp[i][k] + 1);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans;
  return 0;
}