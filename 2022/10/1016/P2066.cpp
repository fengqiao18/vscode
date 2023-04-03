#include <bits/stdc++.h>
using namespace std;
int n, m, a[20][20], pau[20], f[20], ans;
void dfs(int Nnum, int Nans, int Nm) {
  if (Nm < 0) return;
  if (Nnum == n + 1) {
    if (Nans > ans) {
      ans = Nans;
      for (int i = 1; i <= n; i++) {
        f[i] = pau[i];
      }
    }
    return;
  }
  for (int i = 0; i <= m; i++) {
    pau[Nnum] = i, dfs(Nnum + 1, Nans + a[Nnum][i], Nm - i);
  }
  return;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      scanf("%d", &a[i][j]);
  dfs(1, 0, m);
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", i, f[i]);
  }
  return 0;
}