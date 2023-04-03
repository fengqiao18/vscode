#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], lt, rt;
int n, m;
bool check(int x) {
  int cnt = 0, sum = 0;
  for (int i = 1; i <= n; i++) {
    if (sum + a[i] <= x) {
      sum += a[i];
    } else {
      sum = a[i];
      cnt++;
    }
  }
  return cnt >= m;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    lt = max(lt, a[i]);
    rt += a[i];
  }
  while (lt <= rt) {
    int mid = (lt + rt) >> 1;
    if (check(mid)) {
      lt = mid + 1;
    } else {
      rt = mid - 1;
    }
  }
  cout << lt;
  return 0;
}