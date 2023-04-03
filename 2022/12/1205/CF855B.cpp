#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long a[N], dp[N][4];
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, p, q, r;
  cin >> n >> p >> q >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[1][1] = a[1] * p;
  for (int i = 2; i <= n; i++){
    dp[i][1] = max(dp[i - 1][1], a[i] * p);
  }
  dp[1][2] = dp[1][1] + a[1] * q;
  for (int i = 2; i <= n; i++){
    dp[i][2] = max(dp[i - 1][2], dp[i][1] + a[i] * q);
  }
  dp[1][3] = dp[1][2] + a[1] * r;
  for (int i = 2; i <= n; i++){
    dp[i][3] = max(dp[i - 1][3], dp[i][2] + a[i] * r);
  }
  cout << dp[n][3];
  return 0;
}