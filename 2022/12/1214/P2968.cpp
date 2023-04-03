#include <bits/stdc++.h>
using namespace std;
int l, n, ans, m;
const int N = 1e5 + 5;
struct node {
  int t, s, q;
};
bool cmp(node a, node b) {
  return (a.t < b.t);
}
node a[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> l >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].t >> a[i].s;
  }
  sort(a + 1, a + n + 1, cmp);
  a[n].q = a[n].s;
  for (int i = n; i >= 2; i--) {
    a[i - 1].q = min(a[i - 1].s, a[i].q + a[i].t - a[i - 1].t);
  }
  if (a[1].t + 1 <= a[1].q) {
    ans = a[1].t + 1;
  } else {
    ans = (a[1].q + a[1].t + 1) / 2;
  }
  m = min(a[1].q, a[1].t + 1);
  for (int i = 2; i <= n; i++) {
    if (m + a[i].t - a[i - 1].t <= a[i].q) {
      ans = max(ans, m + a[i].t - a[i - 1].t);
    } else {
      ans = max(ans, (a[i].q + a[i].t - a[i - 1].t + m) / 2);
    }
    m = min(a[i].q, m + a[i].t - a[i - 1].t);
  }
  cout << max(ans, m + l - a[n].t);
  return 0;
}