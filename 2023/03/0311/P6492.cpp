#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];
struct node {
  int lx, rx, ans;
};
node tree[4 * N];
void pushup(int cur, int lt, int rt) {
  int mid = (lt + rt) >> 1;
  tree[cur].lx = tree[cur * 2].lx;
  if (tree[cur * 2].lx == mid - lt + 1 && a[mid] != a[mid + 1]) {
    tree[cur].lx += tree[2 * cur + 1].lx;
  }
  tree[cur].rx = tree[cur * 2 + 1].rx;
  if (tree[cur * 2 + 1].rx == rt - mid && a[mid] != a[mid + 1]) {
    tree[cur].rx += tree[cur * 2].rx;
  }
  tree[cur].ans = max(tree[cur * 2].ans, tree[cur * 2 + 1].ans);
  if (a[mid] != a[mid + 1]) {
    tree[cur].ans = max(tree[cur].ans, tree[cur * 2].rx + tree[cur * 2 + 1].lx);
  }
  return;
}
void build(int cur, int lt, int rt) {
  if (lt == rt) {
    a[lt] = 0;
    tree[cur].ans = tree[cur].lx = tree[cur].rx = 1;
    return;
  }
  // cout << lt << " " << rt << endl;
  int mid = (lt + rt) >> 1;
  build(2 * cur, lt, mid);
  build(2 * cur + 1, mid + 1, rt);
  pushup(cur, lt, rt);
  return;
}
void update(int cur, int lt, int rt, int qx) {
  if (qx < lt || rt < qx) {
    return;
  } else if (lt == rt && rt == qx) {
    a[lt] = 1 - a[lt];
    return;
  }
  int mid = (lt + rt) >> 1;
  update(2 * cur, lt, mid, qx);
  update(2 * cur + 1, mid + 1, rt, qx);
  pushup(cur, lt, rt);
  return;
}
signed main() {
  int n, q;
  cin >> n >> q;
  build(1, 1, n);
  for (int i = 1; i <= q; i++) {
    int p;
    cin >> p;
    update(1, 1, n, p);
    cout << tree[1].ans << '\n';
  }
  return 0;
}