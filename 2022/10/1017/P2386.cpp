#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 0;
int a[15] = {1};
void print(int n) {
  for (int i = 1; i <= n; i++)
    cout << a[i] << " ";
  cout << endl;
  return;
}
void dfs(int cur, int sum) {
  if (sum > m || cur > n + 1)
    return;
  if (sum == m && cur <= n + 1) {
    ans++;
    return;
  }
  for (int i = a[cur - 1]; i + sum <= m; i++) {
    a[cur] = i;
    dfs(cur + 1, sum + i);
  }
  return;
}
int main() {
  int t;
  cin >> t;
  a[0] = 1;
  while (t--) {
    cin >> m >> n;
    dfs(1, 0);
    cout << ans << endl;
    ans = 0;
  }
  return 0;
}