#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
struct node {
  int x, dis;
};
vector<node> G[N];
int dis[N];
bool vis[N];
int n, m, s;
void spfa(int s) {
  priority_queue<int> pq;
  for (int i = 1; i <= n; i++) {
    dis[i] = 2147483647;
  }
  dis[s] = 0, vis[s] = 1;
  pq.push(s);
  while (!pq.empty()) {
    int cur = pq.top();
    pq.pop();
    vis[cur] = 0;
    for (int i = 0; i < G[cur].size(); i++) {
      int nxt = G[cur][i].x, w = G[cur][i].dis;
      if (dis[nxt] > dis[cur] + w) {
        dis[nxt] = dis[cur] + w;
        if (vis[nxt] == 0) {
          vis[nxt] = 1;
          pq.push(nxt);
        }
      }
    }
  }
}
int main() {
  cin >> n >> m >> s;
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    G[x].push_back({y, w});
  }
  spfa(s);
  for (int i = 1; i <= n; i++) {
    cout << dis[i] << " ";
  }
  return 0;
}