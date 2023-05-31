#include <bits/stdc++.h>
#define int long long
using namespace std;
int fpow(int a, int b, int p) {
  if (b == 1) {
    return a;
  }
  int ans = 1;
  if (b % 2 == 1) {
    b--;
    ans = a % p;
  }
  int tmp = fpow(a, b / 2, p);
  return (tmp * tmp % p) * ans % p;
}
signed main() {
  int a, b, p;
  cin >> a >> b >> p;
  cout << a << "^" << b << " mod " << p << "=" << fpow(a, b, p);
  return 0;
}