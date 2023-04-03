#include <bits/stdc++.h>
using namespace std;
const int N = 1030;
int G[N][N], deg[N];
stack<int> stk;
int n, m;
void dfs(int x) {
  for (int y = 1; y <= n; y++) {
    if (G[x][y]) {
      G[x][y]--, G[y][x]--;
      dfs(y);
    }
  }
  stk.push(x);
  return;
}
int main() {
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    n = max(n, max(x, y));
    G[x][y]++, G[y][x]++;
    deg[x]++, deg[y]++;
  }
  int t = 1;
  for (int i = 1; i <= n; i++) {
    if (deg[i] % 2) {
      t = i;
      break;
    }
  }
  dfs(t);
  while (!stk.empty()) {
    cout << stk.top() << endl;
    stk.pop();
  }
  return 0;
}
