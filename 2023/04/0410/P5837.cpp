#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
struct E {
  int id, w, f;
};
struct node {
  int x, dis;
  friend bool operator<(const node x, const node y) {
    return x.dis > y.dis;
  }
};
vector<E> G[N];
int n, m;
int dis[N];
bool vis[N];
void dijkstra(int s, int f) {
  priority_queue<node> pq;
  for (int i = 0; i <= n; i++) {
    dis[i] = 2147483647;
  }
  memset(vis, 0, sizeof(vis));
  dis[s] = 0;
  node cur = {s, dis[s]};
  pq.push(cur);
  while (!pq.empty()) {
    int tmp = pq.top().x;
    pq.pop();
    if (vis[tmp]) {
      continue;
    }
    vis[tmp] = 1;
    for (int i = 0; i < G[tmp].size(); i++) {
      int nxt = G[tmp][i].id, w = G[tmp][i].w;
      if (G[tmp][i].f >= f && dis[nxt] > dis[tmp] + w) {
        dis[nxt] = dis[tmp] + w;
        pq.push({nxt, dis[nxt]});
      }
    }
  }
  return;
}
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, c, f;
    cin >> x >> y >> c >> f;
    G[x].push_back({y, c, f});
    G[y].push_back({x, c, f});
  }
  int ans = 0;
  for (int i = 1; i <= 1000; i++) {
    dijkstra(1, i);
    ans = max(ans, 1000000 * i / dis[n]);
  }
  cout << ans;
  return 0;
}