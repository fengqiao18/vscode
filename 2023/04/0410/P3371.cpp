#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
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
int n, m;
int dis[N];
bool vis[N];
void dijkstra(int s) {
  priority_queue<node> pq;
  for (int i = 0; i <= n; i++) {
    dis[i] = 2147483647;
  }
  dis[s] = 0;
  node cur = {s, dis[s]};
  pq.push(cur);
  while (!pq.empty()) {
    int tmp = pq.top().x;
    pq.pop();
    if (vis[tmp]) {
      continue;
    }
    // cout<<tmp<<endl;
    vis[tmp] = 1;
    for (int i = 0; i < G[tmp].size(); i++) {
      int nxt = G[tmp][i].id, w = G[tmp][i].w;
      if (dis[nxt] > dis[tmp] + w) {
        // cout<<"gert";
        dis[nxt] = dis[tmp] + w;
        pq.push({nxt, dis[nxt]});
      }
    }
  }
  return;
}
signed main() {
  int s;
  cin >> n >> m >> s;
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    G[x].push_back({y, w});
  }
  dijkstra(s);
  for (int i = 1; i <= n; i++) {
    cout << dis[i] << " ";
  }
  return 0;
}