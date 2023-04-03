#include <bits/stdc++.h>
using namespace std;
int a[105], dp[25005];
int helper() {
  memset(dp, 0, sizeof(dp));
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = a[i]; j <= a[n]; j++) {
      dp[j] += dp[j - a[i]];
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dp[a[i]] == 1;
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << helper() << endl;
  }
  return 0;
}