#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7 + 5;
ll dp[N];
int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    int w, v;
    cin >> w >> v;
    for (int j = w; j <= m; j++) {
      dp[j] = max(dp[j], dp[j - w] + v);
    }
  }
  cout << dp[m];
  return 0;
}