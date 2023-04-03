#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N], qian[N], f[N][505];
int sum(int l, int r) {
  return qian[r] - qian[l - 1];
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    qian[i] = qian[i - 1] + a[i];
  }
  memset(f , 0 , sizeof(f));
  for (int i = n; i >= 1; i--) {
    for (int j = 1; i + (j * (j - 1) / 2) <= n; j++) {
      if (i != n) {
        f[i][j] = f[i + 1][j];
      }
      if (j == 1 || (i + j <= n && sum(i, i + j - 1) < f[i + j][j - 1])) {
        f[i][j] = max(f[i][j], sum(i, i + j - 1));
      }
    }
  }
  int ans = 1;
  for (int i = 1; i * (i - 1) / 2 <= n; i++) {
    if (f[1][i]) {
      ans = i;
    }
  }
  cout << ans << endl;
  return;
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}