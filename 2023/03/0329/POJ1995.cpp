#include <iostream>
#define int long long
using namespace std;
int qpow(int a, int b, int p) {
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
  int t;
  cin >> t;
  while (t--) {
    int h, ans = 0, p;
    cin >> p >> h;
    for (int i = 1; i <= h; i++) {
      int a, b;
      cin >> a >> b;
      ans = (ans + qpow(a, b, p)) % p;
    }
    cout << ans << '\n';
  }
  return 0;
}