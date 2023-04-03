#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int a[N], dp[N][N];
int main() {
  memset(dp, -63, sizeof(dp));
  int n, h, l, r;
  cin >> n >> h >> l >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < h; j++) {
      dp[i][j] = max(dp[i - 1][(j - a[i] + h) % h], dp[i - 1][(j - a[i] + 1 + h) % h]) + (l <= j && j <= r);
    }
  }
  int maxi = 0;
  for (int i = 0; i < h; i++) {
    maxi = max(maxi, dp[n][i]);
  }
  cout << maxi;
  return 0;
}