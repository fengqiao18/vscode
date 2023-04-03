#include <bits/stdc++.h>
#define db double
#define pai 3.1415926535897932384626
using namespace std;
bool used[7];
int n;
db tx, ty, _x2, _y2, _y1, _x1, x[7], y[7], r[7], ans = 0, d[7][7];

void dfs(int cur, db sum) {
  if (cur == n + 1) {
    ans = max(ans, sum);
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      r[i] = min(min(x[i] - _y1, _x1 - x[i]), min(y[i] - _y2, _x2 - y[i]));
      for (int j = 1; j <= n; j++) {
        if (used[j]) {
          r[i] = min(r[i], d[i][j] - r[j]);
        }
      }
      used[i] = true;
      if (r[i] < 0) {
        r[i] = 0;
      }
      dfs(cur + 1, sum + r[i] * r[i] * pai);
      used[i] = false;
    }
  }
  return;
}
int main(void) {
  cin >> n >> tx >> ty;
  _y1 = _x1 = tx;
  _x2 = _y2 = ty;
  cin >> tx >> ty;
  _y1 = min(_y1, tx), _x1 = max(_x1, tx);
  _y2 = min(_y2, ty), _x2 = max(_x2, ty);
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      d[i][j] = d[j][i] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
    }
  }
  dfs(1, 0);
  int as = (int)((_x2 - _y2) * (_x1 - _y1) - ans + 0.5);
  cout<<as;
  return 0;
}