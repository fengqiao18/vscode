#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if (s == "") {
    cout << "Yes";
    return 0;
  }
  if (s.size() % 2 == 0) {
    cout << "No";
    return 0;
  }
  s = '0' + s;
  for (int i = 1; i < s.size(); i++) {
    if ((s[i * 2] == '#' && s[i * 2 + 1] == '#') || (s[i * 2] != '#' && s[i * 2 + 1] != '#')) {
      continue;
    } else {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}