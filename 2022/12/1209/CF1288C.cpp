#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int p = 1e9 + 7;
const int N = 1005;
const int M = 25;
ll dp[M][N], sum[M][N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  m *= 2;
  for (int i = 1; i <= n; i++) {
    dp[1][i] = 1, sum[1][i] = i;
  }
  for (int i = 2; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = sum[i - 1][j];
      sum[i][j] = ((sum[i][j - 1] + dp[i][j]) % p + p) % p;
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = ((ans + dp[m][i]) % p + p) % p;
  }
  cout << ans;
  return 0;
}