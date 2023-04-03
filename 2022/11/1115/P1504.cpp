#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int w[N], ans[N];
bool dp[N];
int mini = 1e9;
void helper() {
  memset(dp, 0, sizeof(dp));
  int x, cnt = 1, h = 0;
  while (cin >> x) {
    if (x == -1) {
      break;
    }
    w[++cnt] = x, h += x;
  }
  dp[0] = 1;
  mini = min(mini, h);
  for (int i = 1; i <= cnt; i++) {
    for (int j = h; j >= w[i]; j--) {
      dp[j] = dp[j] | dp[j - w[i]];
    }
  }
  for (int i = h; i >= 1; i--) {
    ans[i] += dp[i];
  }
  return;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    helper();
  }
  for (int i = mini; i >= 1; i--) {
    if (ans[i] == n) {
      cout << i;
      return 0;
    }
  }
  cout << 0;
  return 0;
}