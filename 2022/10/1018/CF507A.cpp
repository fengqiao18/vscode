#include <bits/stdc++.h>
using namespace std;
const int N = 105;
struct node {
  int num, id;
};
node a[N];
bool cmp(node x, node y) {
  return x.num < y.num;
}
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].num;
    a[i].id = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  int ans = 0, now = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].num + now <= k) {
      now += a[i].num;
      ans++;
    } else {
      break;
    }
  }
  cout << ans << endl;
  now = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].num + now <= k) {
      now += a[i].num;
      cout << a[i].id << " ";
    } else {
      break;
    }
  }
  return 0;
}