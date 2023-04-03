#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a_[N] , a[N], tree[4 * N], tag[4 * N];
void pushup(int cur) {
  tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
  return;
}
void addtag(int cur, int lt, int rt, int val) {
  tag[cur] += val;
  tree[cur] += (rt - lt + 1) * val;
  return;
}
void pushdown(int cur, int lt, int rt) {
  if (tag[cur] == 0) {
    return;
  }
  int mid = (lt + rt) >> 1;
  addtag(cur * 2, lt, mid, tag[cur]);
  addtag(cur * 2 + 1, mid + 1, rt, tag[cur]);
  tag[cur] = 0;
  return;
}
void build(int cur, int lt, int rt) {
  if (lt == rt) {
    tree[cur] = a[lt];
    return;
  }
  int mid = (lt + rt) >> 1;
  build(cur * 2, lt, mid);
  build(cur * 2 + 1, mid + 1, rt);
  pushup(cur);
  return;
}
void update(int cur, int lt, int rt, int qx, int qy, int val) {
  if (lt > qy || rt < qx) {
    return;
  } else if (rt <= qy && lt >= qx) {
    addtag(cur, lt, rt, val);
    return;
  }
  pushdown(cur, lt, rt);
  int mid = (lt + rt) >> 1;
  update(cur * 2, lt, mid, qx, qy, val);
  update(cur * 2 + 1, mid + 1, rt, qx, qy, val);
  pushup(cur);
  return;
}
int query(int cur, int lt, int rt, int qx, int qy) {
  if (lt > qy || rt < qx) {
    return 0;
  } else if (rt <= qy && lt >= qx) {
    return tree[cur];
  }
  pushdown(cur, lt, rt);
  int mid = (lt + rt) >> 1;
  return query(cur * 2, lt, mid, qx, qy) + query(cur * 2 + 1, mid + 1, rt, qx, qy);
}
signed main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a_[i];
    a[i] = a_[i] - a_[i - 1];
  }
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int opt, x, y;
    cin >> opt >> x >> y;
    if (opt == 1) {
      int val;
      cin >> val;
      update(1, 1, n, x, y, val);
    } else {
      cout << query(1, 1, n, x, y) << '\n';
    }
  }
  return 0;
}