#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N], b[N];
int n, m, cnt;
int ansl, ansr;
bool check(int x) {
  for (int i = 1; i <= m; i++) {
    b[i] = 0;
  }
  cnt = 0;
  for (int i = 1; i <= x; i++) {
    if (b[a[i]] == 0) {
      cnt++;
    }
    b[a[i]]++;
  }
  if (cnt == m) {
    ansl = 1, ansr = x;
    return 1;
  }
  for (int i = 2; i <= n - x + 1; i++) {
    b[a[i - 1]]--;
    if (b[a[i - 1]] == 0) {
      cnt--;
    }
    if (b[a[i + x - 1]] == 0) {
      cnt++;
    }
    b[a[i + x - 1]]++;
    if (cnt == m) {
      ansl = i, ansr = i + x - 1;
      return 1;
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int left = 0, right = n + 1;
  while (left + 1 < right) {
    int mid = (left + right) >> 1;
    if (check(mid)) {
      right = mid;
    } else {
      left = mid;
    }
  }
  check(left);
  cout << ansl << " " << ansr;
  return 0;
}