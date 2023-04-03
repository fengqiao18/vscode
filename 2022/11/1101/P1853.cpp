#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int M = 1e7 + 5;
int dp[M], w[N], val[N];
int main() {
  int s, n, m;
  cin >> s >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> w[i] >> val[i];
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= m; i++) {
      for (int j = w[i]; j <= s; j++) {
        dp[j] = max(dp[j], dp[j - w[i]] + val[i]);
      }
    }
    s += dp[s];
  }
  cout << s;
  return 0;
}