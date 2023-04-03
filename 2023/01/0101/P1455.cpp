#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int c[N], d[N], dp[N], fa[N];
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void unioun(int x, int y) {
  x = find(x), y = find(y);
  if (x != y) {
    fa[x] = y;
    c[y] += c[x];
    d[y] += d[x];
  }
  return;
}
int main() {
  int n, m, money;
  cin >> n >> m >> money;
  for (int i = 1; i <= n; i++) {
    cin >> c[i] >> d[i];
    fa[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    unioun(a, b);
  }
  for (int i = 1; i <= n; i++) {
    if (fa[i] != i) {
      continue;
    }
    for (int j = money; j >= c[i]; j--) {
      dp[j] = max(dp[j], dp[j - c[i]] + d[i]);
    }
  }
  cout << dp[money];
  return 0;
}