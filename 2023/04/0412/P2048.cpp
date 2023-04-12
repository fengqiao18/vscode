#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N], sum[N];
priority_queue<int> pq;
signed main() {
  int n, k, l, r;
  cin >> n >> k >> l >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + l - 1; j <= i + r - 1 && j <= n; j++) {
      pq.push(sum[j] - sum[i - 1]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    ans += pq.top();
    pq.pop();
  }
  cout << ans;
  return 0;
}