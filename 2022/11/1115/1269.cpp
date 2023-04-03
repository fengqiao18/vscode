#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 6005;
int v[N], s[N], w[N];
int dp[M];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i] >> s[i];
    for (int j = m; j >= 0; j--) {
      for (int k = 1; k <= s[i]; k++) {
        if (j >= k * w[i]) {
          dp[j] = max(dp[j], dp[j - k * w[i]] + v[i] * k);
        }
      }
    }
  }
  cout << dp[m];
  return 0;
}