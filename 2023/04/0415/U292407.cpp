#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1 , a + 1 + n);
  while (q--) {
    int x, l, r;
    cin >> x >> l >> r;
    int ans1, ans2;
    int lt = 0, rt = n + 1;
    while (lt + 1 < rt) {
      int mid = (lt + rt) >> 1;
      if (a[mid] * x <= r) {
        lt = mid;
      } else {
        rt = mid;
      }
    }
    ans1 = lt, lt = 0, rt = n + 1;
    while (lt + 1 < rt) {
      int mid = (lt + rt) >> 1;
      if (a[mid] * x >= l) {
        rt = mid;
      } else {
        lt = mid;
      }
    }
    ans2 = lt;
    // cout<<ans1<<" "<<ans2<<"\n";
    if (ans1 >= ans2) {
      cout << ans1 - ans2 << endl;
    } else {
      cout << "0\n";
    }
    // cout<<"-----------------\n";
  }
  return 0;
}