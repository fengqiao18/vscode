#include <bits/stdc++.h>
using namespace std;
const int N = 2e7 + 5;
unsigned long long seed;
inline unsigned long long next_integer() {
  seed ^= seed << 19;
  seed ^= seed >> 31;
  seed ^= seed << 13;
  return seed;
}
int a[N];
int main() {
  int n, m, k, o;
  cin >> n >> m >> k >> o;
  if (o == 0) {
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
  } else {
    cin >> seed;
    for (int i = 1; i <= n; i++) {
      int x = next_integer() % 10000ull, k = next_integer() % 998244353ull;
      if (x <= 1000) {
        next_integer() % (k / 100000);
      } else if (x <= 4000) {
        next_integer() % (k / 10000000);
      } else {
        a[i] = next_integer() % 998244353ull;
      }
    }
  }
  int x = 0 , i;
  for (i = n; i >= 1; i--) {
    if (x + a[i] > k) {
      m--;
      x = 0;
    }
    x += a[i];
    if (m == 0) {
      break;
    }
  }
  cout << n - i;
  return 0;
}
