#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int tree[N];
int n, m;
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
  while (x != 0) {
    sum += tree[x];
    x -= lowbit(x);
  }
  return sum;
}
int main() {
  cin >> n >> m;
  for (int i = 1, j = 0; i <= n; i++) {
    int x;
    cin >> x;
    update(i, x - j);
    j = x;
  }
  while (m--) {
    int opt, x, y, val;
    cin >> opt;
    if (opt == 1) {
      cin >> x >> y >> val;
      update(x, val);
      update(y + 1, -val);
    } else {
      cin >> x;
      cout << query(x) << endl;
    }
  }
  return 0;
}