#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX = 2147483647;
const int N = 1e5 + 5;
struct node {
  int id, w;
  friend bool operator<(const node x , const node y){
    return x.w > y.w;
  }
};
vector<node> G[N];
int dis[N];
bool vis[N];
int n;
void djikstra(int s) {
  memset(vis, 0, sizeof(vis));
  priority_queue<node> pq; 
  node start = {s , 0};
  pq.push(start);
  for (int i = 1; i <= n; i++) {
    dis[i] = MAX;
  }
  dis[s] = 0;
  while(!pq.empty()) {
    int cur = pq.top().id;
    pq.pop();
    if(vis[cur] == 1){
      continue;
    }
    vis[cur] = 1;
    for (int j = 0; j < G[cur].size(); j++) {
      int x = G[cur][j].id, w = G[cur][j].w;
      if (dis[cur] < dis[x] - w) {
        dis[x] = dis[cur] + w;
        node tmp = {x , dis[x]};
        pq.push(tmp);
      }
    }
  }
}
signed main() {
  int m, s, t;
  cin >> n >> m >> s >> t;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].push_back(node{v, w});
    G[v].push_back(node{u, w});
  }
  djikstra(s);
  cout<<dis[t];
  return 0;
}