#include <bits/stdc++.h>
using namespace std;
int dp[100005], w[100005], cnt;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    dp[i] = 1e9;
  }
  for (int i = 1; i * i * i * i <= n; i++) {
    w[++cnt] = i * i * i * i;
  }
  dp[0] = 0;
  for (int i = 1; i <= cnt; i++) {
    for (int j = w[i]; j <= n; j++) {
      dp[j] = min(dp[j], dp[j - w[i]] + 1);
    }
  }
  cout << dp[n];
  return 0;
}