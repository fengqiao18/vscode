#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 5;
int h[N], b[N];
int dp[N][3];
inline int min(int a, int b) { return a > b ? b : a; }
inline int helper(int n) {
  for (int i = 1; i <= n; i++) {
    cin >> h[i] >> b[i];
    dp[i][0] = dp[i][1] = dp[i][2] = 1e18;
  }
  dp[n + 1][0] = dp[n + 1][1] = dp[n + 1][2] = 1e18;
  dp[1][0] = 0, dp[1][1] = b[1], dp[1][2] = b[1] * 2;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 2; j++) {
      for (int k = 0; k <= 2; k++) {
        if (h[i] + j != h[i + 1] + k) {
          dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + b[i + 1] * k);
        }
      }
    }
  }
  int ans = 1e18;
  for (int i = 0; i <= 2; i++) {
    ans = min(ans, dp[n][i]);
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << helper(n) << endl;
  }
  return 0;
}