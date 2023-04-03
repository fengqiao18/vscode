#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool helper(int &n, string &s) {
  int a[N], t[N];
  int cnt = 0;
  s = '*' + s;
  t[++cnt] = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'W') {
      t[++cnt] = i;
    }
  }
  bool flag = 1;
  t[++cnt] = n + 1;
  for (int i = 1; i < cnt; i++) {
    bool r = 0, b = 0;
    if (t[i] + 1 > t[i + 1] - 1) {
      continue;
    }
    for (int j = t[i] + 1; j <= t[i + 1] - 1; j++) {
      if (s[j] == 'R') {
        r = 1;
      }
      if (s[j] == 'B') {
        b = 1;
      }
    }
    if (r == 0 || b == 0) {
      return 0;
    }
  }
  return 1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    cout << (helper(n, s) ? "YES" : "NO") << endl;
  }
  return 0;
}