#include <bits/stdc++.h>
using namespace std;
bool f(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'; }
string s;
int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] += 32;
    }
    if (!f(s[i])) {
      cout << "." << s[i];
    }
  }
  return 0;
}