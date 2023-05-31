#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int a[N], maxi;
int n, m;
bool check(int x) {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += max(0ll, a[i] - x);
  }
  return ans >= m;
}
int erfen() {
  int lt = 0, rt = maxi + 1;
  while (lt + 1 < rt) {
    int mid = (lt + rt) >> 1;
    if (check(mid)) {
      lt = mid;
    } else {
      rt = mid;
    }
  }
  return lt;
}
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    maxi = max(maxi, a[i]);
  }
  cout << erfen();
  return 0;
}