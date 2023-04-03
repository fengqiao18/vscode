#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 5;
struct node {
  int t, b;
};
node a[N];
bool cmp(node x, node y) {
  return x.b < y.b;
}
priority_queue<int, vector<int>, greater<int> > pq;
signed main() {
  int n, k;
  int sum = 0, ans = -1e9;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].t >> a[i].b;
  }
  sort(a + 1, a + 1 + n, cmp);
  for (int i = n; i >= 1; i--) {
    pq.push(a[i].t);
    sum += a[i].t;
    if (k < n - i + 1) {
      sum -= pq.top();
      pq.pop();
    }
    ans = max(ans, sum * a[i].b);
  }
  cout << ans;
  return 0;
}