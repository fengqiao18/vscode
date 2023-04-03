#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int tree[4 * N], a[N], tag[4 * N];
int diff[N];
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
  addtag(2 * cur, lt, mid, tag[cur]);
  addtag(2 * cur + 1, mid + 1, rt, tag[cur]);
  tag[cur] = 0;
  return;
}
void pushup(int cur) {
  tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
  return;
}
void build(int cur, int lt, int rt) {
  if (lt == rt) {
    tree[cur] = diff[lt];
    return;
  }
  int mid = (lt + rt) >> 1;
  build(2 * cur, lt, mid);
  build(2 * cur + 1, mid + 1, rt);
  pushup(cur);
  return;
}
int query(int cur, int lt, int rt, int qx, int qy) {
  if (qx > rt || qy < lt) {
    return 0;
  } else if (qx <= lt && qy >= rt) {
    return tree[cur];
  }
  pushdown(cur, lt, rt);
  int mid = (lt + rt) >> 1;
  return query(cur * 2, lt, mid, qx, qy) + query(cur * 2 + 1, mid + 1, rt, qx, qy);
}
void update(int cur, int lt, int rt, int qx, int qy, int val) {
  if (qx > rt || qy < lt) {
    return;
  } else if (qx <= lt && qy >= rt) {
    addtag(cur, lt, rt, val);
    return;
  }
  pushdown(cur, lt, rt);
  int mid = (lt + rt) >> 1;
  update(2 * cur, lt, mid, qx, qy, val);
  update(2 * cur + 1, mid + 1, rt, qx, qy, val);
  pushup(cur);
  return;
}
signed main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    diff[i] = a[i] - a[i - 1];
  }
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int opt, x, y;
    cin >> opt;
    if (opt == 1) {
      int l, r, k, d;
      cin >> l >> r >> k >> d;
      update(1, 1, n, l + 1, r, d);
      update(1, 1, n, l, l, k);
      update(1, 1, n, r + 1, r + 1, -k - (r - l) * d);
    } else {
      int p;
      cin >> p;
      cout << query(1, 1, n, 1, p) << endl;
    }
  }
  return 0;
}