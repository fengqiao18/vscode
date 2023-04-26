#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int dp[N][21], dp1[N][21], lg[N];
void pre_rmq(int n) {
  lg[0] = -1;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp1[i][0] = a[i];
    lg[i] = lg[i >> 1] + 1;
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
      dp1[i][j] = min(dp1[i][j - 1], dp1[i + (1 << (j - 1))][j - 1]);
    }
  }
  return;
}
int query(int l, int r) {
  int len = lg[r - l + 1];
  int maxi = max(dp[l][len], dp[r - (1 << len) + 1][len]);
  int mini = min(dp1[l][len], dp1[r - (1 << len) + 1][len]);
  return maxi - mini;
}
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  pre_rmq(n);
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << query(l, r) << endl;
  }
  return 0;
}