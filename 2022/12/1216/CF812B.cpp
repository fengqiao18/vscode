#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int a[N][2], f[N][2];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m + 1; j++) {
      char c;
      cin >> c;
      if (c == '1') {
        a[i][0] = max(a[i][0], m + 1 - j);
        a[i][1] = max(a[i][1], j);
      }
    }
  }
  f[n][1] = m + 1;
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 0; j <= 1; j++) {
      f[i][j] = min(f[i + 1][!j] + m + 2, f[i + 1][j] + a[i + 1][!j] * 2 + 1);
    }
  }
  int cur;
  for (cur = 1; cur < n && !a[cur][0]; cur++) {
  }
  cout << min(f[cur][0] + a[cur][1], f[cur][1] + a[cur][0]);
  return 0;
}