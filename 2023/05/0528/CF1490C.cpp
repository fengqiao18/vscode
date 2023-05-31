#include <bits/stdc++.h>
#define int long long
using namespace std;
int f(int x) { return cbrt(x); }
void helper() {
  int x;
  cin >> x;
  for (int i = 1; i <= f(x); i++) {
    int j = x - i * i * i;
    if (i * i * i + f(j) * f(j) * f(j) == x && f(x) > 0) {
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" << endl;
  return;
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    helper();
  }
  return 0;
}