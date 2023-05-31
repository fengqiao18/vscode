#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int id[N], num[N], sum[N], dp[N][N];
int main() {
  int p, q;
  cin >> p >> q;
  for (int i = 1; i <= q; i++) {
    cin >> id[i];
  }
  q++;
  id[q] = p + 1;
  sort(id + 1, id + 1 + q);
  for (int i = 1; i <= q; i++) {
    num[i] = id[i] - id[i - 1] - 1;
  }
  for (int i = 1; i <= q; i++) {
    for (int j = 1; j <= q; j++) {
      dp[i][j] = 1e9; 
    }
  }
  for (int i = 1; i <= q; i++) {
    sum[i] = sum[i - 1] + num[i];
    dp[i][i] = 0;
  }
  for (int len = 2; len <= q; len++) {
    for (int i = 1; i + len - 1 <= q; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1] + j - i - 1);
      }
    }
  }
  cout << dp[1][q];
  return 0;
}