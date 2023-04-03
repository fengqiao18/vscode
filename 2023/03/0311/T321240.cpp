#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct node {
  int l, r;
};
node a[N];
int n;
bool vis[N];
bool cmp(node x, node y) {
  if (x.r != y.r) {
    return x.r < y.r;
  }
  return x.l > y.l;
}
bool check(int x) {
  memset(vis, 0, sizeof(vis));
  if (x == 0) {
    return 1;
  }
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = a[i].l; j < a[i].r; j++) {
      if (vis[j] == 1) {
        continue;
      }
      vis[j] = 1;
      cnt++;
      if (cnt == x) {
        break;
      }
    }
    if (cnt != x) {
      return 0;
    }
  }
  return 1;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].l >> a[i].r;
  }
  sort(a + 1, a + 1 + n, cmp);
  int lt = 0, rt = 1e6, ans = 0;
  while (lt <= rt) {
    int mid = (lt + rt) >> 1;
    if (check(mid)) {
      ans = max(ans, mid);
      lt = mid + 1;
    } else {
      rt = mid - 1;
    }
  }
  cout << ans * n;
  return 0;
}