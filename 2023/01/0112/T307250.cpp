#include <bits/stdc++.h>
#define ll long long
#define lxl __int128
using namespace std;
ll helper() {
  ll n, s, t, x, y;
  cin >> n >> x >> y >> s >> t;
  if (s < t) {
    ll k = (t - s - 1) / y;
    if (n <= k) {
      return n * y + s;
    }
  } else if (s >= t) {
    ll k = (s - t) / x;
    if (n <= k) {
      return s - n * x;
    }
  }
  long long k = (((lxl)s + (lxl)n * y - (lxl)(t - x)) % (x + y) + (x + y)) % (x + y) + (t - x);
  return k;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << helper() << endl;
  }
  return 0;
}