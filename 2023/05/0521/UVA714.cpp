#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
int a[N];
int n, m;
bool check(int x) {
  int cnt = 1, sum = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > x) {
      return 0;
    }
    if (a[i] + sum <= x) {
      sum += a[i];
    } else {
      cnt++;
      sum = a[i];
    }
  }
  return cnt <= m;
}
void helper() {
  int sum = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int lt = 0, rt = sum + 1;
  while (lt + 1 < rt) {
    int mid = (lt + rt) >> 1;
    if (check(mid)) {
      rt = mid;
    } else {
      lt = mid;
    }
  }
  int cnt = 1;
  sum = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] + sum <= rt) {
      sum += a[i];
      cout << a[i] << " ";
    } else {
      cnt++;
      cout << "/ " << a[i] << " ";
      sum = a[i];
    }
  }
  cout << endl;
  return;
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    helper();
  }
  return 0;
}