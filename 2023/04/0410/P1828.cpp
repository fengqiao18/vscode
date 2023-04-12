#include <bits/stdc++.h>
using namespace std;
const int C = 505;
const int N = 805;
struct E {
  int id, w;
};
struct node {
  int x, dis;
  friend bool operator<(const node x, const node y) {
    return x.dis > y.dis;
  }
};
vector<E> G[N];
int dis[N];
bool vis[N];
int cow[C];
int cown, n, m;
void dijkstra(int s) {
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
      if (dis[nxt] > dis[tmp] + w) {
        dis[nxt] = dis[tmp] + w;
        pq.push({nxt, dis[nxt]});
      }
    }
  }
  return;
}
int main() {
  cin >> cown >> n >> m;
  for (int i = 1; i <= cown; i++) {
    cin >> cow[i];
  }
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    G[x].push_back({y, w});
    G[y].push_back({x, w});
  }
  int mini = 1e9;
  for (int i = 1; i <= n; i++) {
    int ans = 0;
    dijkstra(i);
    for (int j = 1; j <= cown; j++) {
      ans += dis[cow[j]];
    }
    // cout << ans << " ";
    mini = min(mini, ans);
  }
  cout << mini;
  return 0;
}