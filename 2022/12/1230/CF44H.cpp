#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 55;
int dp[N][N];
signed main() {
  string s;
  cin >> s;
  int n = s.size();
  if (n == 1) {
    cout << 9;
    return 0;
  }
  s = ' ' + s;
  for (int i = 0; i <= 9; i++){
    dp[1][i] = 1;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= 9; j++) {
      int _ = s[i + 1] - '0';
      dp[i + 1][(j + _) / 2] += dp[i][j];
      if ((_ + j) & 1){
        dp[i + 1][(j + _ + 1) / 2] += dp[i][j];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= 9; i++){
    ans += dp[n][i];
  }
  for (int i = 2; i <= n; i++) {
    if (abs(s[i] - s[i - 1]) >= 2){
      break;
    }
    ans -= (i == n);
  }
  cout << ans;
  return 0;
}