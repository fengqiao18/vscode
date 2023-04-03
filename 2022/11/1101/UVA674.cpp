#include <bits/stdc++.h>
using namespace std;
const int N = 8005;
long long dp[N];
int w[6] = {0, 1, 5, 10, 25, 50};
int main() {
  dp[0] = 1;
  for (int i = 1; i <= 5; i++) {
    for (int j = w[i]; j <= 8000; j++) {
      dp[j] += dp[j - w[i]];
    }
  }
  int n;
  while (cin >> n) {
    cout << dp[n] << "\n";
  }
  return 0;
}