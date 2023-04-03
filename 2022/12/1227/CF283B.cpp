#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
bool f[2][N], vis[2][N];
ll dp[2][N];
int a[N];
int n;
ll dfs(int x, int v) {
  if (x < 1 || x > n) {
    return 0;
  }
  if (f[v][x]) {
    return vis[v][x] ? dp[v][x] : -1;
  }
  f[v][x] = 1;
  ll tmp = dfs(x + (v ? -a[x] : a[x]), v ^ 1);
  vis[v][x] = 1;
  return dp[v][x] = (~tmp ? tmp + a[x] : tmp);
}
int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    a[1] = i;
    ll tmp = ~dfs(a[1] + 1, 1);
    cout << (tmp ? dp[1][a[1] + 1] + a[1] : -1) << endl;
  }
  return 0;
}