#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
const int p = 1e9 + 7;
ll d[10][N];
inline void init(int tot) {
  for (int j = 0; j <= tot; j++) {
    for (int i = 0; i <= 9; i++) {
      if (i + j > 9) {
        d[i][j] = (d[0][i + j - 10] + d[1][i + j - 10]) % p;
      } else {
        d[i][j] = 1;
      }
    }
  }
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  init(2e5);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    ll ans = 0;
    cin >> n >> m;
    while (n != 0) {
      int tmp = n % 10;
      ans = (ans + d[tmp][m]) % p;
      n /= 10;
    }
    cout << ans << endl;
  }
  return 0;
}