#include <bits/stdc++.h>
#define int long long
using namespace std;
int p;
int qpow(int a, int b) {
  int ans = 1;
  while (b != 0) {
    if (b & 1) {
      ans = ans * (a % p) % p;
    }
    b = b >> 1;
    a = (a % p) * (a % p) % p;
  }
  return ans;
}
signed main() {
  int a, b;
  cin >> a >> b >> p;
  cout << a << "^" << b << " mod " << p << "=" << qpow(a, b);
  return 0;
}