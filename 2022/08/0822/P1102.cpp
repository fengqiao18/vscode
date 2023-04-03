#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long ans = 0;
int a[N], n, c;
int er1(int x) {
  int lt = 0, rt = n + 1;
  while (lt + 1 < rt) {
    int mid = (lt + rt) / 2;
    if (a[mid] <= x) {
      lt = mid;
    } else {
      rt = mid;
    }
  }
  return lt;
}
int er2(int x) {
  int lt = 0, rt = n + 1;
  while (lt + 1 < rt) {
    int mid = (lt + rt) / 2;
    if (a[mid] < x) {
      lt = mid;
    } else {
      rt = mid;
    }
  }
  return lt;
}
int main() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    int x = a[i] - c;
    ans += er1(x) - er2(x);
  }
  cout << ans;
  return 0;
}