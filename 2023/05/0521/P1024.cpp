#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-3;
double a, b, c, d;
int cnt = 0;
double f(double x) {
  return a * x * x * x + b * x * x + c * x + d;
}
int main() {
  cout << fixed << setprecision(2);
  cin >> a >> b >> c >> d;
  for (int i = -100; i < 100; i++) {
    double l = i, r = i + 1;
    double x1 = f(l), x2 = f(r);
    if (x1 == 0) {
      cout << l << " ";
      cnt++;
    }
    if (x1 * x2 < 0) {
      while (r - l >= 0.001) {
        double mid = (l + r) / 2;
        if (f(mid) * f(r) <= 0) {
          l = mid;
        } else {
          r = mid;
        }
        // cout<<l<<" "<<r<<endl;
      }
      cout << r << " ";
      cnt++;
    }
    if (cnt == 3) {
      break;
    }
  }
  return 0;
}