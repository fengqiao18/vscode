#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int a[N], dp[N];
bool helper(int n) {
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i] = 0;
  }
  dp[0] = 1;
  for (int i = 0; i <= n; i++) {
    if (i - a[i] >= 1) {
      dp[i] = max(dp[i], dp[i - a[i] - 1]);
    }
    if (i + a[i + 1] + 1 <= n) {
      dp[i + a[i + 1] + 1] = max(dp[i], dp[i + a[i + 1] + 1]);
    }
  }
  return dp[n];
}
signed main() {
  int t, n;
  for (cin >> t; t; t--) {
    cin >> n;
    cout << (helper(n) ? "YES" : "NO") << '\n';
  }
  return 0;
}