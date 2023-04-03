#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n, pos = 0, maxi = -1e9;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int a;
      cin >> a;
      if (maxi < a) {
        maxi = a;
        pos = i;
      }
    }
    cout << pos << endl;
  }
  return 0;
}
