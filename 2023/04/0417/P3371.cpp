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
void spfa(int s) {
  priority_queue<int> pq;
  for (int i = 0; i <= n; i++) {
    dis[i] = 2147483647;
  }
  dis[s] = 0;
  pq.push(s);
  while (!pq.empty()) {
    int tmp = pq.top();
    pq.pop();
    vis[tmp] = 0;
    for (int i = 0; i < G[tmp].size(); i++) {
      int nxt = G[tmp][i].id, w = G[tmp][i].w;
      if (dis[nxt] > dis[tmp] + w) {
        dis[nxt] = dis[tmp] + w;
        if(vis[nxt] == 0){
          vis[nxt] = 1;
          pq.push(nxt);
        }
      }
    }
  }
  return;
}
signed main() {
  int m , s;
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