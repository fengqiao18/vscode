#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
int a[N];
int t, n;
bool check(int x) {
  for (int lt = 1; lt + x - 1 <= n; lt++) {
    int rt = lt + x - 1;
    if (a[rt] <= 0){
      if (-a[lt] <= t) return 1;
    }
    if (a[lt] >= 0){
      if (a[rt] <= t) return 1;
    }
    if (a[lt] <= 0 && a[rt] >= 0){
      if (min(a[rt], -a[lt]) + a[rt] - a[lt] <= t) return 1;
    }
  }
  return 0;
}
int main() {
  cin >> t >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  int lt = -1, rt = n + 1;
  while (lt + 1 < rt) {
    int mid = (lt + rt) >> 1;
    if (check(mid)) {
      lt = mid;
    } else {
      rt = mid;
    }
  }
  cout << lt;
  return 0;
}