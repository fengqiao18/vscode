#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7 + 5;
int diff[N], DIFF[N];
int a[N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int R, L, e, s;
    cin >> L >> R >> s >> e;
    int d = (e - s) / (R - L);
    diff[L] += s, diff[R + 1] -= e;
    DIFF[L + 1] += d, DIFF[R + 1] -= d;
  }
  int maxi = -1e9, ans = 0;
  int sum1 = 0 , sum2 = 0;
  for (int i = 1; i <= n; i++) {
    sum1 = sum1 + DIFF[i];
    sum2 = sum1 + sum2 + diff[i];
    maxi = max(maxi, sum2);
    ans = ans ^ sum2;
  }
  cout << ans << " " << maxi;
  return 0;
}