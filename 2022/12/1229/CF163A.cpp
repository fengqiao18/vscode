#include <bits/stdc++.h>
using namespace std;
const int p = 1e9 + 7;
const int N = 5005;
int dp[N][N];
int main() {
  string s, t;
  cin >> s >> t;
  for (int i = 1; i <= s.size(); i++) {
    for (int j = 1; j <= t.size(); j++) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1] + 1) % p;
      } else {
        dp[i][j] = dp[i][j - 1];
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= s.size(); i++) {
    ans = (ans + dp[i][t.size()]) % p;
  }
  cout << ans;
  return 0;
}