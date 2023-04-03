#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  int n;
  cin >> n;
  int sum_1 = 0, sum0 = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x >= 1) {
      ans += x - 1;
    } else if (x <= -1) {
      ans += -1 - x;
      sum_1++;
    } else if (x == 0) {
      ans += 1;
      sum0++;
    }
  }
  if (sum0 == 0 && sum_1 % 2 == 1) {
    ans += 2;
  }
  cout << ans;
  return 0;
}