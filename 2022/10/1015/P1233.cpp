#include <bits/stdc++.h>
using namespace std;
int n, dp[5005];
struct node {
  int l, w;
} a[5005];
bool cmp(node x, node y) {
  if (x.l != y.l)
    return x.l > y.l;
  return x.w > y.w;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].l >> a[i].w;
  }
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
    for (int j = 1; j <= i - 1; j++) {
      if (a[i].w > a[j].w) 
        dp[i] = max(dp[i], dp[j] + 1);
    }
  }
  int maxi = 0;
  for (int i = 1; i <= n; i++)
    maxi = max(maxi, dp[i]);
  cout << maxi;
  return 0;
}
