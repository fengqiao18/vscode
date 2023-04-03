#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], l = 1e9;
int n, c;
bool check(int num) {
  int cnt = 1, last = a[1];
  for (int i = 2; i <= n; i++) {
    if (a[i] - last > num) {
      last = a[i];
			cnt++;
    }
  }
  return cnt >= c;
}
int erfen() {
  int lt = 0, rt = a[n] - a[1] + 1;
  while (lt < rt) {
    int mid = (lt + rt) >> 1;
    if (check(mid)) {
      lt = mid + 1;
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
    l = min(l, a[i] - a[i - 1]);
  }
  cout << erfen();
  return 0;
}
