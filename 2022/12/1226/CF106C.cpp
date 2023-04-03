#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int dp[N];
int main() {
  int n, m, c, d;
  cin >> n >> m >> c >> d;
  for (int i = 1; i <= n / c; i++) {
    dp[i * c] = i * d;
  }
  int a, b;
  while (m--) {
    cin >> a >> b >> c >> d;
    for (int t = 1; t <= a / b; t++) {
      for (int i = n; i >= c; i--) {
        dp[i] = max(dp[i], dp[i - c] + d);
      }
    }
  }
  int maxi = -1e9;
  for (int i = 1; i <= n; i++) {
    maxi = max(maxi, dp[i]);
  }
  cout << maxi;
  return 0;
}