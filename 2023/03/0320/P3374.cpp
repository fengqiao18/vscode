#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N], tree[N];
int n, m;
int lowbit(int x) {
  return x & -x;
}
void update(int x, int val) {
  while (x <= n) {
    tree[x] += val;
    x += lowbit(x);
  }
  return;
}
int query(int x) {
  int ans = 0;
  while (x) {
    ans += tree[x];
    x -= lowbit(x);
  }
  return ans;
}
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    update(i, a[i]);
  }
  for (int i = 1; i <= m; i++) {
    int opt, x, y;
    cin >> opt >> x >> y;
    if (opt == 1) {
      update(x, y);
    } else {
      cout << query(y) - query(x - 1) << endl;
    }
  }
  return 0;
}