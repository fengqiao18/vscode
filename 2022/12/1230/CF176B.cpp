#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int p = 1e9 + 7;
const int N = 1e5 + 5;
string s, t;
ll f[N][2];
bool check(int l, int r) {
  int j = 0;
  for (int i = l; i <= r; i++) {
    if (s[i] != t[++j]) {
      return 0;
    }
  }
  return 1;
}
int main() {
  int k, cnt = 0;
  cin >> s >> t >> k;
  int n = s.size();
  s = ' ' + s, t = ' ' + t;
  for (int i = 1; i <= n; i++) {
    s = s + s[i];
  }
  for (int i = 1; i <= n; i++) {
    if (check(i, i + n - 1)) {
      cnt++;
    }
  }
  f[0][!check(1, n)] = 1;
  for (int i = 1; i <= k; i++) {
    f[i][0] = (cnt * f[i - 1][1] % p + (cnt - 1) * f[i - 1][0] % p) % p;
    f[i][1] = ((n - cnt) * f[i - 1][0] % p + (n - cnt - 1) * f[i - 1][1] % p) % p;
  }
  cout << f[k][0];
  return 0;
}