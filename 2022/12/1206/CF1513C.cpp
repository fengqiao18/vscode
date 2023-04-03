#include <bits/stdc++.h>
using namespace std;
#define int long long
const int p = 1000000007;
int t, x, m, f[200005][10];
int get(int x) {
  if (x < 0) return 1;
  int ans = 0;
  for (int i = 0; i <= 9; i++) {
    ans = (ans + f[x][i]) % p;
  }
  return ans;
}
signed main() {
  ios ::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> t;
  f[0][1] = f[0][0] = 1;
  for (int i = 1; i <= 200000; i++) {
    for (int j = 9; j >= 1; j--) {
      f[i][j] = f[i - 1][j - 1];
    }
    f[i][0] = 0;
    f[i][0] = (f[i][0] + f[i - 1][9]) % p;
    f[i][1] = (f[i][1] + f[i - 1][9]) % p;
  }
  while (t--) {
    cin >> x >> m;
    int ans = 0;
    while (x) {
      int d = x % 10;
      ans = (ans + get(m - (10 - d))) % p;
      x /= 10;
    }
    cout << ans;
  }
  return 0;
}