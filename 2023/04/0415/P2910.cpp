#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 1e4 + 5;
int n, m;
int dis[N][N];
int a[M];
void floyd() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
      }
    }
  }
  return;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> dis[i][j];
    }
  }
  floyd();
  int ans = 0;
  for (int i = 2; i <= m; i++) {
    ans += dis[a[i - 1]][a[i]];
  }
  cout << ans;
  return 0;
}