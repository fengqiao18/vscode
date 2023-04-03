#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int t[N], g[N][N];
int n, m;
inline void update(int k) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    }
  }
}
int main() {
  // freopen("1.in" , "r" , stdin);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  memset(g, 0x3f, sizeof(g));
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    g[x][y] = g[y][x] = min(g[x][y], w);
  }
  for (int i = 0; i < n; i++) {
    g[i][i] = 0;
  }
  int q, cur = 0;
  cin >> q;
  while (q--) {
    int x, y, tm;
    cin >> x >> y >> tm;
    while (cur < n && t[cur] <= tm) {
      update(cur);
      cur++;
    }
    if (t[x] > tm || t[y] > tm || g[x][y] == 0x3f3f3f3f) {
      cout << -1;
    } else {
      cout << g[x][y];
    }
    cout << endl;
  }
  return 0;
}