#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int a[N], diff[N];
int s, t, ans;
int get_temp(int x) { return x > 0 ? -(x * s) : -x * t; }
signed main() {
  int n, q;
  cin >> n >> q >> s >> t;
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
    if (i > 0) {
      diff[i] = a[i] - a[i - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    ans += get_temp(diff[i]);
  }
  for (int i = 1; i <= q; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    ans -= get_temp(diff[l]);
    diff[l] += x;
    ans += get_temp(diff[l]);
    if (r == n) {
      cout << ans << endl;
      continue;
    }
    ans -= get_temp(diff[r + 1]);
    diff[r + 1] -= x;
    ans += get_temp(diff[r + 1]);
    cout << ans << endl;
  }
  return 0;
}
