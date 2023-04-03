#include <bits/stdc++.h>
using namespace std;
int w[10] = {0, 1, 2, 3, 5, 10, 20}, num[15];
int dp[1005], ans;
int main() {
  for (int i = 1; i <= 6; i++) {
    cin >> num[i];
  }
  dp[0] = 1;
  for (int i = 1; i <= 6; i++) {
    for (int j = 1000; j >= 0; j--) {
      for (int k = 1; k <= num[i]; k++) {
        if (j >= k * w[i]) {
          dp[j] += dp[j - w[i] * k];
        }
      }
    }
  }
  for (int i = 1; i <= 1000; i++) {
    ans += dp[i] != 0;
  }
  cout << "Total=" << ans;
  return 0;
}