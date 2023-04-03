#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, s;
vector<int> v[N];
bool vis[N];
inline void dfs(int cur) {
  if (vis[cur]) {
    return;
  }
  vis[cur] = 1;
  cout << cur << " ";
  for (int i = 0; i < v[cur].size(); i++) {
    dfs(v[cur][i]);
  }
  return;
}
inline void bfs(int s) {
  bool vis[N] = {0};
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  while (!q.empty()) {
    int cur = q.front();
    cout << cur << " ";
    q.pop();
    for (int i = 0; i < v[cur].size(); i++) {
      if (vis[v[cur][i]] == 0) {
        q.push(v[cur][i]);
        vis[v[cur][i]] = 1;
      }
    }
  }
  return;
}
int main() {
  cin >> n >> m >> s;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(s);
  cout << endl;
  bfs(s);
  return 0;
}