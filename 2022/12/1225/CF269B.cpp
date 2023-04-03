#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N], dp[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    double _;
    cin >> a[i] >> _;
    dp[i] = 1;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (a[i] >= a[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  int __ = 0;
  for (int i = 1; i <= n; i++) {
    __ = max(__, dp[i]);
  }
  cout << n - __;
  return 0;
}