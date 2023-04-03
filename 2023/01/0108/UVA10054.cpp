#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int G[N][N], dge[N];
inline void dfs(int x) {
  for (int y = 1; y <= 50; y++) {
    if (G[x][y] > 0) {
      G[x][y]--, G[y][x]--;
      dfs(y);
      cout << y << " " << x << endl;
    }
  }
  return;
}
inline void helper(int n) {
  memset(G, 0, sizeof(G));
  memset(dge, 0, sizeof(dge));
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    G[x][y]++, G[y][x]++;
    dge[x]++, dge[y]++;
  }
  int i = 1;
  while (i <= 50) {
    if (dge[i] % 2) {
      break;
    }
    i++;
  }
  if (i <= 50) {
    cout << "some beads may be lost\n\n";
    return;
  }
  for (i = 1; i <= 50; i++) {
    dfs(i);
  }
  cout << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n;
    cin >> n;
    cout << "Case #" << i << endl;
    helper(n);
  }
  return 0;
}
