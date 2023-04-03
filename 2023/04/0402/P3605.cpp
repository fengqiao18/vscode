#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], tree[N], ans[N];
vector<int> G[N];
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
  int ans = 0;
  while (x) {
    ans += tree[x];
    x -= lowbit(x);
  }
  return ans;
}
void lisan(int n) {
  int b[N];
  for (int i = 1; i <= n; i++) {
    b[i] = a[i];
  }
  int len = unique(a + 1, a + 1 + n) - (a + 1);
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    b[i] = lower_bound(a + 1, a + 1 + n, b[i]) - a;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = b[i];
  }
  return;
}
void dfs(int cur) {
  int tmp1 = query(n) - query(a[cur]);
  for (int i = 0; i < G[cur].size(); i++) {
    int x = G[cur][i];
    dfs(x);
  }
  int tmp2 = query(n) - query(a[cur]);
  ans[cur] = tmp2 - tmp1;
  update(a[cur], 1);
  return;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  lisan(n);
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    G[x].push_back(i);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}