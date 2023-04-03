#include <bits/stdc++.h>
using namespace std;
const int N = 55;
long long sum[N], dp[N];
int a[N];
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n; i >= 1; i--) {
    sum[i] = sum[i + 1] + a[i];
  }
  dp[n] = a[n];
  for (int i = n; i >= 1; i--) {
    dp[i] = max(dp[i + 1], sum[i + 1] - dp[i + 1] + a[i]);
  }
  cout << sum[1] - dp[1] << " " << dp[1] << endl;
  return 0;
}