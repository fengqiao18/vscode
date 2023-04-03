#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 150;
int n, m, k;
int num[N];
int cost[N][N], dp[N][N][N];
signed main() {
  memset(dp, 0x3f, sizeof(dp));
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> cost[i][j];
    }
  }
  if (num[1] != 0) {
    dp[1][num[1]][1] = 0;
  } else {
    for (int i = 1; i <= m; i++) {
      dp[1][i][1] = cost[1][i];
    }
  }
  for (int i = 2; i <= n; i++) {
    if (num[i] != 0) {
      for (int l = 1; l <= k; l++) {
        for (int o = 1; o <= m; o++) {
          dp[i][num[i]][l] = min(dp[i][num[i]][l], dp[i - 1][o][l - (o == num[i] ? 0 : 1)]);
        }
      }
    } else {
      for (int j = 1; j <= m; j++) {
        for (int l = 1; l <= k; l++) {
          for (int o = 1; o <= m; o++) {
            dp[i][j][l] = min(dp[i][j][l], dp[i - 1][o][l - (o == j ? 0 : 1)] + cost[i][j]);
          }
        }
      }
    }
  }
  int ans = 1e18;
  for (int i = 1; i <= m; i++) {
    ans = min(ans, dp[n][i][k]);
  }
  if (ans == 1e18) {
    cout << -1;
  } else {
    cout << ans;
  }
  return 0;
}
