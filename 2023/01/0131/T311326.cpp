#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-4;
const int N = 1e5 + 5;
struct node {
  double l, r;
} a[N];
int n;
bool cmp(node x, node y) {
  if (x.l != y.l) {
    return x.l < y.l;
  }
  return x.r < y.r;
}
bool check(double t) {
  double k = 0;
  for (int i = 1; i <= n; i++) {
    if (k < a[i].l) {
      k = a[i].l;
    }
    k += t;
    if (k > a[i].r) {
      return 0;
    }
  }
  return 1;
}
int main() {
  cin >> n;
  double lt = 0, rt = 1e5;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].l >> a[i].r;
    rt = min(rt, a[i].r - a[i].l + 1);
  }
  sort(a + 1, a + n + 1, cmp);
  while (rt - lt > eps) {
    double mid = (rt + lt) / 2;
    if (check(mid)) {
      lt = mid;
    } else {
      rt = mid;
    }
  }
  cout << fixed << setprecision(2) << lt;
  return 0;
}