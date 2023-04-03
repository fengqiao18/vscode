#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int tree[4 * N], a[N], tag[4 * N];
void addtag(int cur, int lt, int rt) {
  tag[cur] = !tag[cur];
  tree[cur] = (rt - lt + 1) - tree[cur];
  return;
}
void pushdown(int cur, int lt, int rt) {
  if (tag[cur] == 0) {
    return;
  }
  int mid = (lt + rt) >> 1;
  addtag(2 * cur, lt, mid);
  addtag(2 * cur + 1, mid + 1, rt);
  tag[cur] = 0;
  return;
}
void pushup(int cur) {
  tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
  return;
}
void build(int cur, int lt, int rt) {
  if (lt == rt) {
    tree[cur] = a[lt];
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
void update(int cur, int lt, int rt, int qx, int qy) {
  if (qx > rt || qy < lt) {
    return;
  } else if (qx <= lt && qy >= rt) {
    addtag(cur, lt, rt);
    return;
  }
  pushdown(cur, lt, rt);
  int mid = (lt + rt) >> 1;
  update(2 * cur, lt, mid, qx, qy);
  update(2 * cur + 1, mid + 1, rt, qx, qy);
  pushup(cur);
  return;
}
signed main() {
  int n, m;
  cin >> n >> m;
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int opt, l, r;
    cin >> opt >> l >> r;
    if (opt == 0) {
      update(1, 1, n, l, r);
    } else {
      cout << query(1, 1, n, l, r) << '\n';
    }
  }
  return 0;
}