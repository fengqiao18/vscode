#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
struct E {
  int id, w;
};
vector<E> G[N];
int dis[N], cnt[N];
bool vis[N];
int n, m, s;
bool spfa(int s) {
  memset(vis, 0, sizeof(vis));
  priority_queue<int> pq;
  pq.push(s);
  for (int i = 1; i <= n; i++) {
    dis[i] = 2147483647;
  }
  dis[s] = 0;
  while (!pq.empty()) {
    int tmp = pq.top();
    pq.pop();
    vis[tmp] = 0;
    for (int i = 0; i < G[tmp].size(); i++) {
      int nxt = G[tmp][i].id, w = G[tmp][i].w;
      if (dis[tmp] + w < dis[nxt]) {
        dis[nxt] = dis[tmp] + w;
        if (vis[nxt] == 0) {
          vis[nxt] = 1;
          pq.push(nxt);
          cnt[nxt] = cnt[tmp] + 1;
          if (cnt[nxt] >= n) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}
bool helper() {
  memset(cnt, 0, sizeof(cnt));
  memset(dis, 0, sizeof(dis));
  for (int i = 1; i <= n; i++) {
    G[i].clear();
  }
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    if (w >= 0) {
      G[y].push_back({x, w});
    }
    G[x].push_back({y, w});
  }
  return spfa(1);
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    cout << (helper() ? "YES" : "NO") << endl;
  }
  return 0;
}