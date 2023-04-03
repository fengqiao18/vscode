#include <bits/stdc++.h>
using namespace std;
int dp[200][200];
const int dx[] = {0 , -2 , -1 , 1 , 2};
const int dy[] = {0 , -1 , -2 , -2 , -1};
int main() {
  dp[0][0] = 1;
  int n, m;
  cin>>n>>m;
  for (int j = 1; j <= m; j++) {
    for (int i = 0; i <= n; i++) {
      for (int k = 1; k <= 4; k++) {
        int xx = i + dx[k], yy = j + dy[k];
        if (xx >= 0 && yy >= 0 && xx <= n && yy <= m) {
          dp[i][j] += dp[xx][yy];
        }
      }
      // cout << dp[i][j] << " ";
    }
    // cout << endl;
  }
  cout<<dp[n][m];
  return 0;
}