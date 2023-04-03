#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int M = 1e4 + 5;
int a[N], dp[M];
int n, m;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= a[i]; j--) {
      dp[j] = dp[j] + dp[j - a[i]];
    }
  }
  cout << dp[m];
  return 0;
}