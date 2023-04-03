#include <bits/stdc++.h>
using namespace std;
long long f(char c) { return c - 'A' + 1; }
long long mpow(int m, int k) { return k == 0 ? 1 : m * pow(m, k - 1); }
int main() {
  unsigned long long ans = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    ans += f(s[i]) * mpow(26, s.size() - i - 1);
  }
  cout << ans;
  return 0;
}