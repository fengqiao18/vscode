#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
const int mod = 100003;
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
int dis[N], dp[N];
bool vis[N];
void dijkstra(int s) {
  priority_queue<node> pq;
  for (int i = 0; i <= n; i++) {
    dis[i] = 1e9;
  }
  dis[s] = 0, dp[s] = 1;
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
        // cout<<"gert";
        dp[nxt] = dp[tmp];
        dis[nxt] = dis[tmp] + w;
        pq.push({nxt, dis[nxt]});
      } else if (dis[nxt] == dis[tmp] + w) {
        dp[nxt] = (dp[tmp] + dp[nxt]) % mod;
      }
    }
    // for(int i = 1 ; i <= n ; i++){
    //   cout<<dp[i]<<" ";
    // }
    // cout<<endl;
  }
  return;
}
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    G[x].push_back({y, 1});
    G[y].push_back({x, 1});
  }
  dijkstra(1);
  for (int i = 1; i <= n; i++) {
    cout << (dis[i] == 1e9 ? 0 : dp[i]) << "\n";
  }
  return 0;
}