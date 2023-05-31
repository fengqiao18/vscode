#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int dp[N][N];
int v[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    dp[i][i] = v[i] * n;
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      dp[i][j] = max(dp[i + 1][j] + v[i] * (n - len + 1), dp[i][j - 1] + v[j] * (n - len + 1));
    }
  }
  cout << dp[1][n];
  return 0;
}