#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int maxi = -1e9;
double g[N][N];
struct node {
  int x, y;
};
node a[N];
int n, m;
inline void floyd() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }
  return;
}
inline double getdis(int p, int q) {
  double tmp1 = (a[p].x - a[q].x) * (a[p].x - a[q].x);
  double tmp2 = (a[p].y - a[q].y) * (a[p].y - a[q].y);
  return sqrt(tmp1 + tmp2);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      g[i][j] = 1e9;
    }
    g[i][i] = 0;
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x][y] = g[y][x] = getdis(x, y);
  }
  floyd();
  int s, t;
  cin >> s >> t;
  cout << fixed << setprecision(2) << g[s][t];
  return 0;
}