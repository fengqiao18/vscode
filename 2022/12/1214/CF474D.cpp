#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int p = 1e9 + 7;
const int N = 1e5 + 5;
int n, k;
ll dp[N], sum[N];
inline void init(int maxi) {
  dp[0] = 1;
  for (int i = 1; i <= maxi; i++) {
    dp[i] = dp[i - 1];
    if (i >= k && (dp[i] += dp[i - k]) >= p) {
      dp[i] -= p;
    }
  }
  for (int i = 1; i <= maxi; i++) {
    sum[i] = (sum[i - 1] + dp[i]) % p;
  }
  return;
}
int main() {
  cin >> n >> k;
  init(1e5);
  while (n--) {
    int l, r;
    cin >> l >> r;
    cout << (sum[r] - sum[l - 1] + p) % p << endl;
  }
  return 0;
}