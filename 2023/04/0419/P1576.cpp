#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
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
double dis[N];
bool vis[N];
void spfa(int s) {
  priority_queue<int> pq;
  for (int i = 0; i <= n; i++) {
    dis[i] = 1e9;
  }
  dis[s] = 1;
  pq.push(s);
  while (!pq.empty()) {
    int tmp = pq.top();
    pq.pop();
    vis[tmp] = 0;
    for (int i = 0; i < G[tmp].size(); i++) {
      int nxt = G[tmp][i].id;
      double w = G[tmp][i].w;
      if (dis[nxt] > dis[tmp] / (1 - w)) {
        dis[nxt] = dis[tmp] / (1 - w);
        // cout<< fixed << setprecision(8)<<dis[nxt]<<" "<<w + 1<<endl;
        if (vis[nxt] == 0) {
          vis[nxt] = 1;
          pq.push(nxt);
        }
      }
    }
  }
  return;
}
signed main() {
  int m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    double w;
    cin >> x >> y >> w;
    w = w * 1.0 / 100;
    G[x].push_back({y, w});
    G[y].push_back({x, w});
  }
  int s, k;
  cin >> s >> k;
  spfa(k);
  // for (int i = 1; i <= n; i++) {
  //   cout << fixed << setprecision(8) << dis[i] << " ";
  // }
  cout << fixed << setprecision(8) << dis[s] * 100;
  return 0;
}
