#include <bits/stdc++.h>
using namespace std;
const int M = 1e7 + 1;
const int N = 5e5 + 1;
long long a[N], cnt[M], ans;
int f(int v) {
  return v < M ? cnt[v] : 0;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int tmp = 0;
  for (int i = 1; i <= 1e7; i++) {
    if (cnt[i]) {
      a[++tmp] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] * 3 == m) {
      long long tmp = (cnt[a[i]] * (cnt[a[i]] - 1) * (cnt[a[i]] - 2)) / 6;
      // cout<<tmp;
      ans += tmp;
    }
    if (a[i] * 3 < m) {
      ans += cnt[a[i]] * (cnt[a[i]] - 1) / 2 * f(m - 2 * a[i]);
      if (a[i] % 2 == m % 2) {
        int tmp = f((m - a[i]) / 2);
        ans += cnt[a[i]] * tmp * (tmp - 1) / 2;
      }
    }
    for (int j = i + 1; j <= n && a[i] + a[j] * 2 < m; j++) {
      ans += cnt[a[i]] * cnt[a[j]] * f(m - a[i] - a[j]);
    }
  }
  cout << ans;
  return 0;
}