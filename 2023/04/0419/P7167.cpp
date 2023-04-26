#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int d[N], c[N], nxt[N][21];
int sum[N][21];
stack<int> stk;
int n, q;
void pre_rmq() {
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) <= n; i++) {
      nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
      sum[i][j] = sum[i][j - 1] + sum[nxt[i][j - 1]][j - 1];
    }
  }
  return;
}
int query(int cur, int val) {
  if (val <= c[cur]) {
    return cur;
  }
  val -= c[cur];
  for (int i = 19; i >= 0; i--) {
    if (nxt[cur][i] != 0 && val > sum[cur][i]) {
      val -= sum[cur][i];
      cur = nxt[cur][i];
    }
  }
  return nxt[cur][0];
}
signed main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> d[i] >> c[i];
  }
  memset(sum, 0x3f, sizeof(sum));
  for (int i = 1; i <= n; i++) {
    while (!stk.empty() && d[stk.top()] < d[i]) {
      int cur = stk.top();
      nxt[cur][0] = i;
      sum[cur][0] = c[i];
      stk.pop();
    }
    stk.push(i);
  }
  pre_rmq();
  while (q--) {
    int r, v;
    cin >> r >> v;
    cout << query(r, v) << '\n';
  }
  return 0;
}