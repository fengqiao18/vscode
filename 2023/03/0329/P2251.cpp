#include <bits/stdc++.h>
#define rint register int
using namespace std;
const int N = 3e6 + 5;
int n, m, len;
int dp[N][21];
int a[N], lg[N];
inline void pre_rmq() {
  lg[0] = -1;
  for (rint i = 1; i <= n; i++) {
    dp[i][0] = a[i];
    lg[i] = lg[i >> 1] + 1;
  }
  for (rint j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }
  }
  return;
}
int get(int l, int r) {
  len = lg[r - l + 1];
  return min(dp[l][len], dp[r - (1 << len) + 1][len]);
}
int main() {
  cin >> n >> m;
  for (rint i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  pre_rmq();
  for (int i = 1; i <= n - m + 1; i++) {
    int l = i , r = i + m - 1;
    printf("%d\n", get(l, r));
  }
  return 0;
}