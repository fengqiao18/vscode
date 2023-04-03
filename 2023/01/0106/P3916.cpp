#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
int a[N];
inline void dfs(int cur, int maxi) {
  if (a[cur] != 0) {
    return;
  }
  a[cur] = maxi;
  for (int i = 0; i < g[cur].size(); i++) {
    dfs(g[cur][i], maxi);
  }
  return;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[v].push_back(u);
  }
  for (int i = n; i >= 1; i--) {
    dfs(i, i);
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
