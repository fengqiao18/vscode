#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
const int N = 1e5 + 5;
long long ans = 0;
int m, n, a[N];
int erfen(int x) {
  int lt = 0, rt = m + 1;
  while (lt + 1 < rt) {
    int mid = (lt + rt) / 2;
    if (a[mid] > x) {
      rt = mid;
    } else {
      lt = mid;
    }
  }
  return min(abs(a[rt] - x), abs(a[lt] - x));
}
int main() {
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + m);
  a[0] = -inf;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    ans += erfen(x);
  }
  cout << ans;
  return 0;
}