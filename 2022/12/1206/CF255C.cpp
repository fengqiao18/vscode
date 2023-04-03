#include <bits/stdc++.h>
using namespace std;
const int N = 4005;
int a[N], f[N][N];
int n, cnt, ans;
map<int, int> m;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (m[a[i]] == 0) {
      m[a[i]] = ++cnt;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      f[i][m[a[j]]] = max(f[i][m[a[j]]], f[j][m[a[i]]] + 1);
      ans = max(ans, f[i][m[a[j]]]);
    }
  }
  cout << ans + 1;
  return 0;
}