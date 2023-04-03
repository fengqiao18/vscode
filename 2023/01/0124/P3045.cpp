#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e4 + 5;
priority_queue<int, vector<int>, greater<int> > q;
struct node {
  int p, c;
} a[N];
bool cmp(node x, node y) {
  return x.c < y.c;
}
bool compare(node x, node y) {
  return x.p < y.p;
}
signed main() {
  int n, k, m;
  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].p >> a[i].c;
  }
  sort(a + 1, a + n + 1, cmp);
  int ans = 0, tot = 0;
  for (int i = 1; i <= k; i++) {
    ans += a[i].c;
    q.push(a[i].p - a[i].c);
    if (ans > m) {
      cout << tot;
      return 0;
    }
    tot++;
  }
  sort(a + 1 + k, a + n + 1, compare);
  for (int i = k + 1; i <= n; i++) {
    int tmp = q.empty() ? 1e18 : q.top();
    if (a[i].p - a[i].c > tmp) {
      ans += tmp + a[i].c;
      q.pop();
      q.push(a[i].p - a[i].c);
    } else {
      ans += a[i].p;
    }
    if (ans > m) {
      break;
    }
    tot++;
  }
  cout << tot;
  return 0;
}
