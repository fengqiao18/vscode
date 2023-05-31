#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int a[N];
int n;
bool check(long long x) {
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] <= x) {
      sum += x - a[i];
    } else {
      return 0;
    }
  }
  return sum >= x;
}
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  long long lt = 0, rt = 1e14 + 2;
  while (lt + 1 < rt) {
    long long mid = (lt + rt) / 2;
    if (check(mid)) {
      rt = mid;
    } else {
      lt = mid;
    }
  }
  cout << rt;
  return 0;
}