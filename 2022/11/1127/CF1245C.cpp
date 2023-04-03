#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
string s;
ll f[N];
void init(int len) {
  f[0] = f[1] = 1;
  for (int i = 2; i <= len; i++) {
    f[i] = (f[i - 1] + f[i - 2]) % mod;
  }
  return;
}
void check(int i) {
  if (s[i] == 'w' || s[i] == 'm') {
    cout << 0;
    exit(0);
  }
  return;
}
int main() {
  cin >> s;
  int len = s.size();
  init(len);
  s = s + ' ';
  len++;
  ll ans = 1 , cnt = 1;
  check(0);
  for (int i = 1; i < len; i++) {
    check(i);
    if (s[i] == s[i - 1] && (s[i] == 'u' || s[i] == 'n')) {
      cnt++;
    } else {
      if (cnt == 1) {
        continue;
      }
      ans = ans * f[cnt] % mod;
      cnt = 1;
    }
  }
  cout << ans;
  return 0;
}
