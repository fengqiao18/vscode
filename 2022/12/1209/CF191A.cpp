#include <bits/stdc++.h>
using namespace std;
const int N = 26;
int dp[N][N] = {0};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int len = s.size();
    int j = s[0] - 'a', k = s[len - 1] - 'a';
    for (int m = 0; m < 26; m++) {
      if (dp[m][j] != 0) {
        dp[m][k] = max(dp[m][k], dp[m][j] + len);
      }
    }
    dp[j][k] = max(dp[j][k], len);
  }
  int ans = -1e9;
  for (int i = 0; i < 26; i++) {
    ans = max(ans, dp[i][i]);
  }
  cout << ans;
  return 0;
}