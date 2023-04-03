#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N], tree[4 * N];
int mod;
void pushup(int cur) {
  tree[cur] = (tree[cur * 2] * tree[cur * 2 + 1]) % mod;
  return;
}
void build(int cur, int lt, int rt) {
  if (lt == rt) {
    tree[cur] = 1;
    return;
  }
  int mid = (lt + rt) >> 1;
  build(cur * 2, lt, mid);
  build(cur * 2 + 1, mid + 1, rt);
  pushup(cur);
  return;
}
void update(int cur, int lt, int rt, int qx, int val) {
  if(qx < lt || qx > rt){
    return ;
  }
  if(lt == rt && lt == qx){
    tree[cur] = val;
    return ;
  }
  int mid = (lt + rt) >> 1;
  // cout<<cur<<" ";
  update(cur * 2, lt, mid, qx, val);
  update(cur * 2 + 1, mid + 1, rt, qx, val);
  pushup(cur);
  return;
}
void helper() {
  int q, m;
  cin >> q >> m;
  mod = m;
  build(1, 1, q);
  for (int i = 1; i <= q; i++) {
    int opt, x;
    cin >> opt >> x;
    if (opt == 1) {
      update(1, 1, q, i, x);
      cout << tree[1] % m << '\n';
    } else {
      update(1, 1, q, x, 1);
      cout << tree[1] % m << '\n';
    }
  }
  return;
}
signed main() {
  // freopen("1.in" , "r" , stdin);
  int t;
  cin >> t;
  while (t--) {
    helper();
  }
  return 0;
}