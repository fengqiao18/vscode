#include <bits/stdc++.h>
using namespace std;
const int N = 805;
int a[N], g[N][N];
int n, p, c;
inline void floyd() {
  for (int k = 1; k <= p; k++) {
    for (int i = 1; i <= p; i++) {
      for (int j = i; j <= p; j++) {
        if(g[i][j] > g[i][k] + g[k][j]){
          g[i][j] = g[j][i] = g[i][k] + g[k][j];
        }
      }
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> p >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(g, 0x3f, sizeof(g));
  for (int i = 1; i <= p; i++) {
    g[i][i] = 0;
  }
  for (int i = 1; i <= c; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    g[x][y] = g[y][x] = min(g[x][y], w);
  }
  floyd();
  long long mini = 1e18;
  for (int i = 1; i <= p; i++) {
    long long sum = 0;
    for (int j = 1; j <= n; j++) {
      sum += g[a[j]][i];
    }
    mini = min(mini, sum);
  }
  cout << mini;
  return 0;
}