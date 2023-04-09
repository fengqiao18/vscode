#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = n * (n + 1) / 2;
    int jian = 1;
    while (jian <= n) {
      ans -= jian * 2;
      jian *= 2;
    }
    cout << ans << endl;
  }
  return 0;
}