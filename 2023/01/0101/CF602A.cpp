#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int f(int n, int bx) {
  int x = 0;
  while (n--) {
    int d;
    cin >> d;
    x = x * bx + d;
  }
  return x;
}
signed main() {
  int n, bx, m, by;
  cin >> n >> bx;
  int x = f(n, bx);
  cin >> m >> by;
  int y = f(m, by);
  if (x < y) {
    cout << '<';
  } else if (x == y) {
    cout << '=';
  } else {
    cout << '>';
  }
  return 0;
}
