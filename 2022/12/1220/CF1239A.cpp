#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int p = 1e9 + 7;
int f[N];
int main() {
  int n, m;
  cin >> m >> n;
  f[1] = f[0] = 1;
  for (int i = 2; i <= max(n, m); i++) {
    f[i] = (f[i - 1] + f[i - 2]) % p;
  }
  cout << ((f[n] + f[m] - 1) % p) * 2 % p;
  return 0;
}