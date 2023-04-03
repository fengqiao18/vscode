#include <bits/stdc++.h>
using namespace std;
string s, a;
int n, cnt;
void print(int x) {
  if (x >= pow(2, n)) {
    cout << s[x];
    return;
  }
  print(x * 2);
  print(x * 2 + 1);
  cout << s[x];
  return;
}
int main() {
  cin >> n >> a;
  a = '*' + a;
  for (int i = pow(2, n); i < pow(2, n + 1); i++) {
    if (a[++cnt] == '1') {
      s[i] = 'I';
    } else {
      s[i] = 'B';
    }
  }
  for (int i = pow(2, n) - 1; i >= 1; i--) {
    if (s[i * 2] == 'I' && s[i * 2 + 1] == 'I') {
      s[i] = 'I';
    } else if (s[i * 2] == 'B' && s[i * 2 + 1] == 'B') {
      s[i] = 'B';
    } else {
      s[i] = 'F';
    }
  }
  print(1);
  return 0;
}
