#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e3 + 5;
long long dp[N];
int p[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 2; i <= n + 1; i++) {
    dp[i] = (dp[i - 1] + dp[i - 1] - dp[p[i - 1]] + 2 + mod) % mod;
  }
  cout << dp[n + 1];
  return 0;
}
