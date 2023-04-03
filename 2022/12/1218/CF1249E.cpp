#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], b[N], dp[N][2];
int main() {
  int n, c;
  cin >> n >> c;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    cin >> b[i];
  }
  cout << 0 << " ";
  dp[1][1] = 1e9;
  for (int i = 2; i <= n; i++) {
    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i - 1];
    dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + c) + b[i - 1];
    cout << min(dp[i][0], dp[i][1]) << " ";
  }
  return 0;
}