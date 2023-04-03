#include <bits/stdc++.h>
using namespace std;
string s;
int lef(char c, int k) {
  int cnt = 0;
  for (int i = 0; i < k; i++) {
    cnt += s[i] == c;
  }
  return cnt;
}
int rig(char c, int k) {
  int cnt = 0;
  for (int i = k + 1; i < s.size(); i++) {
    cnt += s[i] == c;
  }
  return cnt;
}
int main() {
  cin >> s;
  long long ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      long long c1 = lef('Q', i), c2 = rig('Q', i);
      ans += c1 * c2;
    }
  }
  cout << ans;
  return 0;
}