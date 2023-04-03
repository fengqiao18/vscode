#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int sum[N], dp[N][2];
char c;
int main() {
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = dp[0][1] = 0;
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++) {
      char c = ' ';
      while (c != '#' && c != '.'){
        c = getchar();
      }
      if (c == '#'){
        sum[j]++;
      }
    }
  }
  for (int i = 1; i <= m; i++){
    sum[i] += sum[i - 1];
  }
  for (int i = 0; i < m; i++)
    for (int j = x; j <= y; j++) {
      if (i + j > m){
        break;
      }
      dp[i + j][0] = min(dp[i + j][0], dp[i][1] + sum[i + j] - sum[i]);
      dp[i + j][1] = min(dp[i + j][1], dp[i][0] + n * j - sum[i + j] + sum[i]);
    }
  cout << min(dp[m][0], dp[m][1]);
  return 0;
}