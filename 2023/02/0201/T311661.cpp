#include <bits/stdc++.h>
using namespace std;
const int N = 255;
const int p = 1e6;
int n, w[N], sum;
int dp[N * 2000];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    sum += w[i];
  }
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = sum / 2; j >= w[i]; j--) {
      dp[j] = (dp[j] + dp[j - w[i]]) % p;
    }
  }
  for (int i = sum / 2; i >= 0; i--) {
    if (dp[i] != 0) {
      cout << sum - i - i << endl
           << dp[i];
      break;
    }
  }
  return 0;
}
