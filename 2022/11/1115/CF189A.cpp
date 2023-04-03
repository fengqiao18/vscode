#include <bits/stdc++.h>
using namespace std;
int n, w[5], dp[4005];
int main() {
  cin >> n;
  for (int i = 1; i <= 3; i++) {
    cin >> w[i];
  }
  for (int i = 1; i <= 4000; i++) {
    dp[i] = -1e9;
  }
  dp[0] = 0;
  for (int i = 1; i <= 3; i++) {
    for (int j = w[i]; j <= n; j++) {
      dp[j] = max(dp[j], dp[j - w[i]] + 1);
    }
  }
  cout << dp[n];
  return 0;
}