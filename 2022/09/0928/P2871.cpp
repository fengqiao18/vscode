#include <bits/stdc++.h>
using namespace std;
const int N = 13005;
int a[N], b[N];
int dp[N];
int main() {
  int m, n;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= a[i]; j--) {
      dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
    }
  }
  cout << dp[m];
  return 0;
}