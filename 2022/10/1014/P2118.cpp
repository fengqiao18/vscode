#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  }
  return gcd(b, a % b);
}
double mini = 1e9, mina, minb;
int main() {
  int a, b, l;
  cin >> a >> b >> l;
  double ans = a * 1.0 / b;
  // cout<<ans<<endl;
  for (int i = 1; i <= l; i++) {
    for (int j = 1; j <= l; j++) {
      double tmp = i * 1.0 / j;
      // cout << i << " " << j << " " << tmp << endl;
      if (gcd(i, j) == 1 && tmp >= ans && tmp - ans < mini) {
        mini = tmp - ans;
        mina = i, minb = j;
      }
    }
  }
  cout << mina << " " << minb;
  return 0;
}