#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int M = 1e4 + 5;
int a[N], f[M];
int n, m;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= a[i]; j--) {
      f[j] = f[j] + f[j - a[i]];
    }
  }
  cout << f[m];
  return 0;
}