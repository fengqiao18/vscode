#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
double dp[N][N], ans;
int main() {
  int n, t;
  double p;
  scanf("%d%lf%d", &n, &p, &t);
  dp[0][0] = 1;
  for (int i = 1; i <= t; i++) {
    dp[i][0] = dp[i - 1][0] * (1 - p);
    for (int j = 1; j < n; j++) {
      dp[i][j] = dp[i - 1][j - 1] * p + dp[i - 1][j] * (1 - p);
    }
    dp[i][n] = dp[i - 1][n - 1] * p + dp[i - 1][n];
  }
  double ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += i * dp[t][i];
  }
  printf("%.9lf", ans);
  return 0;
}