#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
struct E {
  int id;
  double w;
};
struct node {
  int x;
  double dis;
  friend bool operator<(const node x, const node y) {
    return x.dis > y.dis;
  }
};
vector<E> G[N];
int n, m;
double dis[N], x[N], y[N];
bool vis[N];
double getdis(int i, int j) {
  return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
void dijkstra(int s) {
  priority_queue<node> pq;
  for (int i = 0; i <= n; i++) {
    dis[i] = 1e9;
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
      int nxt = G[tmp][i].id;
      double w = G[tmp][i].w;
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
  int s, t;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    double w = getdis(x, y);
    G[x].push_back({y, w});
    G[y].push_back({x, w});
  }
  cin >> s >> t;
  dijkstra(s);
  cout << fixed << setprecision(2) << dis[t];
  return 0;
}