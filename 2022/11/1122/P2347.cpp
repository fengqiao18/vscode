#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10;
const int M = 1005;
const int w[N] = {0, 1, 2, 3, 5, 10, 20};
int dp[M], num[N];
signed main() {
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
  int cnt = 0;
  for (int i = 1; i <= 1000; i++) {
    cnt += (dp[i] != 0);
  }
  cout << "Total=" << cnt;
  return 0;
}