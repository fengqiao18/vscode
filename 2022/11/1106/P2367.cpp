#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
long long a[N], diff[N];
int main() {
  int n, p;
  cin >> n >> p;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    diff[i] = a[i] - a[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    diff[x] += z, diff[y + 1] -= z;
  }
  long long mini = 1e18;
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + diff[i];
    mini = min(mini, a[i]);
  }
  cout << mini;
  return 0;
}