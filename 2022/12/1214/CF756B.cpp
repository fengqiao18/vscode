#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t[N], dp[N];
int main() {
  // freopen("1.out" , "w" , stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  t[0] = 2e9;
  for (int i = 1; i <= n; i++) {
    int pos1 = lower_bound(t, t + n + 1, t[i] - 89) - t;
    int pos2 = lower_bound(t, t + n + 1, t[i] - 1439) - t;
    dp[i] = dp[i - 1] + 20;
    if (i - pos1 >= 2) {
      dp[i] = min(dp[i], dp[pos1 - 1] + 50);
    }
    if (i - pos2 >= 5) {
      dp[i] = min(dp[i], dp[pos2 - 1] + 120);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << dp[i] - dp[i - 1] << endl;
  }
  return 0;
}