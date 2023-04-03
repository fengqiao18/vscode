#include <bits/stdc++.h>
using namespace std;
int cnt, w[1005];
long long dp[1005];
bool is_Prime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}
int main() {
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    if (is_Prime(i)) {
      w[++cnt] = i;
    }
  }
  dp[0] = 1;
  for (int i = 1; i <= cnt; i++) {
    for (int j = w[i]; j <= n; j++) {
      dp[j] += dp[j - w[i]];
    }
  }
  cout << dp[n];
  return 0;
}