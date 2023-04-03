#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> G[N];
int a[N], tree[N], ans[N];
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
void lisan(int n) {
  int b[N];
  for (int i = 1; i <= n; i++) {
    b[i] = a[i];
  }
  sort(a + 1, a + 1 + n);
  int len = unique(a + 1, a + 1 + n) - (a + 1);
  for (int i = 1; i <= n; i++) {
    b[i] = lower_bound(a + 1, a + 1 + len, b[i]) - a;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = b[i];
  }
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