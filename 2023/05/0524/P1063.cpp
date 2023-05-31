#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, a[2 * N], dp[2 * N][2 * N], maxi = -1e9;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  int m = 2 * n;
  for (int i = 2; i < m; i++) {
    for (int j = i - 1; j >= 1 && i - j < n; j--) {
      for (int k = j; k < i; k++) {
        dp[j][i] = max(dp[j][i], dp[j][k] + dp[k + 1][i] + a[j] * a[k + 1] * a[i + 1]);
      }
      maxi = max(maxi, dp[j][i]);
    }
  }
  cout << maxi;
  return 0;
}