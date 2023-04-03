#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int tree[N], ans[N];
int n, m;
int lowbit(int x) {
  return x & -x;
}
void update(int x, int val) {
  while (x <= 32001) {
    tree[x] += val;
    x += lowbit(x);
  }
  return;
}
int query(int x) {
  int sum = 0;
  while (x != 0) {
    sum += tree[x];
    x -= lowbit(x);
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    x++;
    ans[query(x)]++;
    update(x, 1);
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}