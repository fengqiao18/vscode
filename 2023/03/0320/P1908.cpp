#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n;
struct node {
  int num, id;
  friend bool operator<(const node x, const node y) {
    if (x.num != y.num) {
      return x.num < y.num;
    }
    return x.id < y.id;
  }
};
node a[N];
int tree[N];
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
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].num;
    a[i].id = i;
  }
  sort(a + 1, a + 1 + n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += i - 1 - query(a[i].id);
    update(a[i].id, 1);
  }
  cout << ans;
  return 0;
}