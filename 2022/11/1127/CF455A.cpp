#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int maxi = -1e9;
long long num[N] , dp[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    num[x]++, maxi = max(maxi, x);
  }
  dp[1] = num[1];
  for (int i = 2; i <= maxi; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + num[i] * i);
  }
  cout << dp[maxi];
  return 0;
}