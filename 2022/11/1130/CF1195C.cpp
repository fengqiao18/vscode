#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long a[N][2], dp[N][3];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= 1; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[j][i];
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
    dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
    dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
  }
  cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
  return 0;
}