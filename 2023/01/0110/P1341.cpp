#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int n, m, deg[N];
bool g[N][N];
int a[N];
stack<char> stk;
void dfs(int cur) {
  for (int i = 0; i < 300; i++) {
    if (g[i][cur] != 0) {
      g[cur][i] = g[i][cur] = 0;
      dfs(i);
    }
  }
  stk.push((char)cur);
  return;
}
int main() {
  int m, mini = 1e9;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    char u, v;
    cin >> u >> v;
    mini = min(mini, (int)min(u, v));
    g[u][v] = g[v][u] = 1;
    deg[v]++, deg[u]++;
  }
  int cnt = 0;
  for (int i = 0; i < 300; i++) {
    if (deg[i] % 2 == 1) {
      a[++cnt] = i;
    }
  }
  // cout << cnt << endl;
  if (cnt == 0) {
    dfs(mini);
  } else if (cnt == 2) {
    dfs(a[1]);
  } else {
    cout << "No Solution";
    return 0;
  }
  while (!stk.empty()) {
    cout << stk.top();
    stk.pop();
  }
  return 0;
}