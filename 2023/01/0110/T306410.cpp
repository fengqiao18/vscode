#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;
int sum1[N], sum2[N];
int ans;
int a[N];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  for (int i = 1; i <= 2 * n; i++) {
    sum1[i] = a[i] + sum1[i - 1];
    sum2[i] = sum2[i - 1] + (a[i] * (a[i] + 1) / 2);
    // cout << sum1[i] << " " << sum2[i] << endl;
  }
  for (int i = 1, j = 0; i <= 2 * n; i++) {
    while (sum1[i] - sum1[j] > x) {
      j++;
    }
    if (sum1[j] >= x) {
      int tmp = sum2[i] - sum2[j];
      int res = x - sum1[i] + sum1[j];
      // cout << tmp <<" "<< res << endl;
      tmp += (2 * a[j] + 1 - res) * res / 2;
      ans = max(ans, tmp);
    }
  }
  cout << ans;
  return 0;
}