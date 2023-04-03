#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct node {
  int l, r, id;
  friend bool operator<(const node x, const node y) {
    if (x.r != y.r) {
      return x.r < y.r;
    }
    return x.l < y.l;
  }
};
node q[N];
int a[N], pos[N], ans[N], tree[N];
int n;
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
  int sum = 0;
  while (x) {
    sum += tree[x];
    x -= lowbit(x);
  }
  return sum;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> q[i].l >> q[i].r;
    q[i].id = i;
  }
  sort(q + 1, q + 1 + m);
  int lr = 0;
  for (int t = 1; t <= m; t++) {
    for (int i = lr + 1; i <= q[t].r; i++) {
      if (pos[a[i]] != 0) {
        update(pos[a[i]], -1);
      }
      update(i, 1);
      pos[a[i]] = i;
    }
    lr = q[t].r;
    ans[q[t].id] = query(q[t].r) - query(q[t].l - 1);
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}