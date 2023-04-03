#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N * 4], tree[4 * N];
int mod;
void pushup(int cur) {
  tree[cur] = ((tree[cur * 2] % mod) * (tree[cur * 2 + 1] % mod)) % mod;
  return;
}
void update(int cur, int lt, int rt, int qx, int val) {
  if (lt > qx || rt < qx) {
    return;
  } else if (lt == qx && rt == qx) {
    tree[cur] = val;
    return;
  }
  int mid = (lt + rt) >> 1;
  update(cur * 2, lt, mid, qx, val);
  update(cur * 2 + 1, mid + 1, rt, qx, val);
  pushup(cur);
  return;
}
void helper() {
  for (int i = 1; i <= 4e5; i++) {
    tree[i] = 1;
  }
  int q;
  cin >> q >> mod;
  for (int i = 1; i <= q; i++) {
    int opt, m;
    cin >> opt >> m;
    if (opt == 1) {
      update(1, 1, q, i, m);
      cout << tree[1] % mod << endl;
    } else {
      update(1, 1, q, m, 1);
      cout << tree[1] % mod << endl;
    }
  }
  return;
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    helper();
  }
  return 0;
}