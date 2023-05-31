#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], n, k;
bool check(int mid) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[i] / mid;
  }
  return sum >= k;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int lt = 0, rt = 1e8 + 1;
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