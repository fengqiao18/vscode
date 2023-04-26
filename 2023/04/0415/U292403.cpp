#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N], cnt[505];
signed main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] % k == 0) {
      ans += cnt[0];
    } else {
      ans += cnt[k - a[i] % k];
    }
    cnt[a[i] % k]++;
  }
  cout << ans;
  return 0;
}