#include <bits/stdc++.h>
using namespace std;
const int N = 105, M = 25005;
long long a[N], dp[M];
inline int helper() {
  int n, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = a[i]; j <= a[n]; j++) {
      dp[j] += dp[j - a[i]];
    }
  }
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