#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N], diff[N];
int z, f;
signed main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    diff[i] = a[i] - a[i - 1];
  }
  for (int i = 2; i <= n; i++) {
    if (diff[i] > 0) {
      z += diff[i];
    } else {
      f += diff[i];
    }
  }
  cout << max(z, -f) << "\n"
       << llabs(z + f) + 1;
  return 0;
}