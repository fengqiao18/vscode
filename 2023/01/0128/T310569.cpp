#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
int dp[N];
inline void init(int n) {
  dp[1] = 1, dp[2] = 1, dp[3] = 2;
  for (int i = 4; i <= n; i++) {
    if (i % 2 == 1) {
      dp[i] = dp[i / 2 + 1] * 2 - 1;
    } else {
      dp[i] = dp[i / 2] + dp[i / 2 + 1] - 1;
    }
  }
  return;
}
int main() {
  init(1e7);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 2) {
      cout << "2";
    } else {
      cout << dp[n];
    }
    cout << endl;
  }
  return 0;
}
