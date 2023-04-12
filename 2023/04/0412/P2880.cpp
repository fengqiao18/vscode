#include <bits/stdc++.h>
#define rint register int
using namespace std;
const int N = 3e6 + 5;
int n, m, len;
int dp[N][21] , dp1[N][21];
int a[N], lg[N];
inline void pre_rmq() {
  lg[0] = -1;
  for (rint i = 1; i <= n; i++) {
    dp[i][0] = dp1[i][0] = a[i];
    lg[i] = lg[i >> 1] + 1;
  }
  for (rint j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
      dp1[i][j] = min(dp1[i][j - 1], dp1[i + (1 << (j - 1))][j - 1]);
    }
  }
  return;
}
int rans(int l, int r) {
  len = lg[r - l + 1];
  return max(dp[l][len], dp[r - (1 << len) + 1][len]) - min(dp1[l][len], dp1[r - (1 << len) + 1][len]);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (rint i = 1; i <= n; i++) {
    cin >> a[i];
  }
  pre_rmq();
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    cout << rans(l, r) << '\n';
  }
  return 0;
}