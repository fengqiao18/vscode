#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int d[6][6] = {{0, 0, 0, 0, 0, 0},
                     {0, 5, -1, -2, -1, -3},
                     {0, -1, 5, -3, -2, -4},
                     {0, -2, -3, 5, -2, -2},
                     {0, -1, -2, -2, 5, -1},
                     {0, -3, -4, -2, -1, 0}};
int a[N], b[N];
int dp[N][N];
int helper(char t) {
  if (t == 'A') {
    return 1;
  }
  if (t == 'C') {
    return 2;
  }
  if (t == 'G') {
    return 3;
  }
  if (t == 'T') {
    return 4;
  }
  cout << "INPUT ERORR!";
  exit(0);
  return -1;
}
int main() {
  string s1, s2;
  int tmp;
  cin >> tmp >> s1 >> tmp >> s2;
  for (int i = 0; i < s1.size(); i++) {
    a[i + 1] = helper(s1[i]);
  }
  for (int i = 0; i < s2.size(); i++) {
    b[i + 1] = helper(s2[i]);
  }
  for (int i = 1; i <= s1.size(); i++) {
    dp[i][0] = dp[i - 1][0] + d[a[i]][5];
  }
  for (int i = 1; i <= s2.size(); i++) {
    dp[0][i] = dp[0][i - 1] + d[5][b[i]];
  }
  for (int i = 1; i <= s1.size(); i++) {
    for (int j = 1; j <= s2.size(); j++) {
      dp[i][j] = max(dp[i - 1][j - 1] + d[a[i]][b[j]], max(dp[i - 1][j] + d[a[i]][5], dp[i][j - 1] + d[5][b[j]]));
      // cout<<dp[i][j]<<' ';
    }
    // cout<<endl;
  }
  cout << dp[s1.size()][s2.size()];
  return 0;
}