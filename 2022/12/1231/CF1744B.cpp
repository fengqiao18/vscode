#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N];
void helper(int n, int q) {
  int odd = 0, even = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    if (a[i] & 1) {
      odd++;
    } else {
      even++;
    }
  }
  while (q--) {
    int c, x;
    cin >> c >> x;
    if (c == 0) {
      sum += even * x;
      if (x & 1) {
        odd = n;
        even = 0;
      }
    } else {
      sum += odd * x;
      if (x & 1) {
        even = n;
        odd = 0;
      }
    }
    cout << sum << endl;
  }
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    helper(n, q);
  }
  return 0;
}
