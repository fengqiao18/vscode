#include <bits/stdc++.h>
using namespace std;
const int N = 405;
const int M = 4e4 + 5;
struct node {
  int h, a, c;
};
node a[N];
int maxi, dp[M];
bool cmp(node x, node y) { return x.a < y.a; }
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].h >> a[i].a >> a[i].c;
    maxi = max(maxi, a[i].a);
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= a[i].c; j++) {
      for (int k = a[i].a; k >= a[i].h; k--) {
        dp[k] = max(dp[k], dp[k - a[i].h] + a[i].h);
      }
    }
  }
  int ans = -1e9;
  for (int i = 1; i <= maxi; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans;
  return 0;
}