#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  char a, b, c, d, e;
  cin >> n >> a >> b >> c >> d >> e;
  if (d >= '6') {
    d = '0';
  }
  if (n == 12) {
    if (a == '0' && b == '0') {
      b = '1';
    } else if (10 * (a - '0') + (b - '0') > 12 && b > '0') {
      a = '0';
    } else if (10 * (a - '0') + (b - '0') > 12 && b == '0') {
      a = '1';
    }
  }
  if (n == 24) {
    if (10 * (a - '0') + (b - '0') >= 24) {
      a = '0';
    }
  }
  cout << a << b << c << d << e;
  return 0;
}