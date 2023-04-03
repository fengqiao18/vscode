#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k;
bool check(int x) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += min(m, x / i);
  }
  return sum < k;
}
signed main() {
  cin >> n >> m >> k;
  int lt = 1, rt = n * m + 1;
  while (lt < rt) {
    int mid = (lt + rt) / 2;
    if (check(mid)) {
      lt = mid + 1;
    } else {
      rt = mid;
    }
  }
  cout << lt;
  return 0;
}
