#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 300;
bool vis[M][M];
int v[N][M], dp[N];
int main() {
  string s;
  int n, m;
  cin >> n >> s >> m;
  s = '*' + s;
  for (int i = 1; i <= m; i++) {
    char a, b;
    cin >> a >> b;
    vis[a][b] = vis[b][a] = 1;
  }
  for (int i = 'a'; i <= 'z'; i++) {
    v[1][i] = -1;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 'a'; j <= 'z'; j++) {
      v[i][j] = v[i - 1][j];
    }
    v[i][s[i - 1]] = i - 1;
  }
  int ans = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 'a'; j <= 'z'; j++) {
      if (!vis[s[i]][j] && v[i][j] != -1) {
        dp[i] = max(dp[i], dp[v[i][j]] + 1);
      } else {
        dp[i] = max(dp[i], 1);
      }
    }
    ans = max(ans, dp[i]);
  }
  cout << n - ans;
  return 0;
}