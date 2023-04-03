#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int p = 998244353;
int f[N], pow2[N];
int main() {
  int n;
  cin >> n;
  pow2[0] = 1;
  for (int i = 1; i <= n; i++) {
    pow2[i] = (pow2[i - 1] * 2) % p;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      f[j] = (f[j] + 1) % p;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int tmp = ((long long)pow2[max(n - i - 1, 0)] * f[i]) % p;
    ans = (ans + tmp) % p;
  }
  cout << ans;
  return 0;
}