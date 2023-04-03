#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m;
int s[N], t[N], d[N], r[N], diff[N], a[N];
bool check(int x) {
  for (int i = 1; i <= n; i++) {
    diff[i] = r[i] - r[i - 1];
  }
  for (int i = 1; i <= x; i++) {
    diff[s[i]] -= d[i], diff[t[i] + 1] += d[i];
  }
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + diff[i];
    if (a[i] < 0) {
      return 1;
    }
  }
  return 0;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> d[i] >> s[i] >> t[i];
  }
  int lt = 0, rt = m + 1;
  while (lt + 1 < rt) {
    int mid = (rt + lt) >> 1;
    if (check(mid)) {
      rt = mid;
    } else {
      lt = mid;
    }
  }
  if (rt == m + 1) {
    cout << 0;
  } else {
    cout << -1 << endl
         << rt;
  }
  return 0;
}