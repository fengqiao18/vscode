#include <bits/stdc++.h>
using namespace std;
const int N = 30;
string s;
int vis[N];
int G[N][N];
int indeg[N], outdeg[N];
void dfs(int x) {
  vis[x] = 0;
  for (int i = 1; i <= 26; i++) {
    if (G[x][i] && vis[i]) {
      dfs(i);
    }
  }
  return;
}
bool helper() {
  memset(G, 0, sizeof(G));
  memset(vis, 0, sizeof(vis));
  memset(indeg, 0, sizeof(indeg));
  memset(outdeg, 0, sizeof(outdeg));
  int n, t;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    int u = s[0] - 'a' + 1;
    int v = s[s.size() - 1] - 'a' + 1;
    G[u][v]++, G[v][u]++;
    outdeg[u]++, indeg[v]++;
    vis[u] = vis[v] = 1;
    t = u;
  }
  dfs(t);
  int cntin = 0, cntout = 0;
  for (int i = 1; i <= 26; i++) {
    if (vis[i]) {
      return 0;
    }
    if (indeg[i] != outdeg[i]) {
      if (indeg[i] - outdeg[i] == 1) {
        cntin++;
      } else if (indeg[i] - outdeg[i] == -1) {
        cntout++;
      } else {
        return 0;
      }
    }
  }
  return (cntin == 1 && cntout == 1) || (cntin == 0 && cntout == 0);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    if (helper()) {
      cout << "Ordering is possible." << endl;
    } else {
      cout << "The door cannot be opened." << endl;
    }
  }
  return 0;
}