#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 8e4 + 5;
int a[N], diff[N], ans[N];
signed main() {
  int n, opt, mod, mini, maxi;
  cin >> n >> opt >> mod >> mini >> maxi;
  for (int i = 1; i <= opt; i++) {
    int l, r, x;
    char c;
    cin >> c >> l >> r;
    if (c == 'A') {
      cin >> x;
      diff[l] += x;
      diff[r + 1] -= x;
    } else {
      int cnt = 0;
      for (int j = 1; j <= r; j++) {
        a[j] = a[j - 1] + diff[j];
        int tmp = (a[j] * j) % mod;
        if (tmp >= mini && tmp <= maxi && j >= l) {
          cnt++;
        }
      }
      cout << cnt << endl;
    }
  }
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + diff[i];
    int tmp = a[i] * i % mod;
    ans[i] = ans[i - 1];
    if (tmp >= mini && tmp <= maxi) {
      ans[i]++;
    }
  }
  int end;
  cin >> end;
  for (int i = 1; i <= end; i++) {
    int l, r;
    cin >> l >> r;
    cout << ans[r] - ans[l - 1] << "\n";
  }
  return 0;
}