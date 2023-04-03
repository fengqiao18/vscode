#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int p = 1e9 + 7;
long long s[N * 2];
int b, t;
void caco(int o) {
  for (; t > 1 && o / 2 <= s[t - 1] / 2; t -= 2) {
    if (s[t - 1] % 4 == 0) {
      s[t - 2] = (s[t - 2] + s[t]) % p;
    } else if (s[t - 1] % 4 == 1) {
      s[t - 2] = (s[t - 2] - s[t] + p) % p;
    } else {
      s[t - 2] = (s[t] * s[t - 2]) % p;
    }
  }
  return;
}
int main() {
  for (char c; cin >> c;) {
    if (c >= '0' && c <= '9') {
      cin.putback(c) >> s[++t];
    } else if (c == '(') {
      b += 4;
    } else if (c == ')') {
      b -= 4;
    } else {
      int o = b + (c != '+') + (c == '*');
      caco(o);
      s[++t] = o;
    }
  }
  caco(-1);
  cout << s[1];
  return 0;
}