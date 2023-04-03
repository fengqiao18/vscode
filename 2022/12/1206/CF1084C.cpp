#include <bits/stdc++.h>
using namespace std;
const int p = 1e9 + 7;
int cnt, x;
string s;
int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a') {
      cnt = (cnt + x + 1) % p;
    } else if (s[i] == 'b') {
      x = cnt;
    } else {
      continue;
    }
  }
  cout << cnt;
  return 0;
}