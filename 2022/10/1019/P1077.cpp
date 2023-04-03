#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int p = 1000007;
int n, m, a[N], dp[N][N];
int dfs(int x, int y) {
  if (y > m) {
    return 0;
  }
  if (y == m) {
    return 1;
  }
  if (x == n + 1) {
    return 0;
  }
  if (dp[x][y]) {
    return dp[x][y]; 
  }
  int ans = 0;
  for (int i = 0; i <= a[x]; i++){
    ans = (ans + dfs(x + 1, y + i)) % p;
  } 
  dp[x][y] = ans; 
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cout << dfs(1, 0) << endl;
  return 0;
}