#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200005;
int n, a[N], dp[N];
bool vis[N];
int dfs(int x) {
  if (x < 1)
    return -1e9;
  if (vis[x] == true) {
    return dp[x];
  }
  vis[x] = true;
  return dp[x] = max(a[x], dp[x - 1] + a[x]);
}
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int maxi = -1e9;
  for (int i = 1; i <= n; i++) {
    maxi = max(maxi, dfs(i));
  }
  cout << maxi;
  return 0;
}