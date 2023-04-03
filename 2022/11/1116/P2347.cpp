#include <bits/stdc++.h>
using namespace std;
const int w[10] = {0, 1, 2, 3, 5, 10, 20};
const int N = 1005;
long long dp[N], num[10];
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
  int ans = 0;
  for (int i = 1; i <= 1000; i++) {
    ans += dp[i] != 0;
  }
  cout << "Total=" << ans;
  return 0;
}