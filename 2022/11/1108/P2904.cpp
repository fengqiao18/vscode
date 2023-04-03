#include <bits/stdc++.h>
using namespace std;
const int N = 2505;
int dp[N], sum[N], w[N], val[N];
int main() {
  int n, m;
  cin >> n >> m;
  sum[0] = m;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    sum[i] = sum[i - 1] + x;
    w[i] = i;
    dp[i] = 1e9;
    val[i] = sum[i] + m;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = w[i]; j <= n; j++) {
      dp[j] = min(dp[j], dp[j - w[i]] + val[i]);
    }
  }
  cout << dp[n] - m;
  return 0;
}