#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
long long a[N], sum[N], ans = 0;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    ans += a[i] * (i - 1) - sum[i - 1];
  }
  cout << ans * 2;
  return 0;
}