#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node {
  int g, x;
};
node a[N];
bool cmp(node x, node y) {
  return x.x < y.x;
}
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].g >> a[i].x;
  }
  sort(a + 1, a + 1 + n, cmp);
  int sum = 0, ans = -1e9;
  int j = 1;
  for (int i = 1; i <= n; i++) {
    sum += a[i].g;
    for (; a[i].x > a[j].x + 2 * k; j++) {
      sum -= a[j].g;
    }
    ans = max(ans, sum);
  }
  cout << ans;
  return 0;
}
