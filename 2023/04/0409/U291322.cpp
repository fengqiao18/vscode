#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int n, k;
int erfen(int x) {
  int l = 0, r = n + 1;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (a[mid] == x) {
      return mid;
    } else if (a[mid] > x) {
      r = mid;
    } else {
      l = mid;
    }
  }
  return 0;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (erfen(a[i] + k)) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
