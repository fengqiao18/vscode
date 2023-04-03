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
vector<node> G[N] , G1[N];
int dis[N] , dis1[N];
bool vis[N] , vis1[N];
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
void djikstra1(int s) {
  memset(vis1, 0, sizeof(vis1));
  priority_queue<node> pq1; 
  node start = {s , 0};
  pq1.push(start);
  for (int i = 1; i <= n; i++) {
    dis1[i] = MAX;
  }
  dis1[s] = 0;
  while(!pq1.empty()) {
    int cur = pq1.top().id;
    pq1.pop();
    if(vis1[cur] == 1){
      continue;
    }
    vis1[cur] = 1;
    for (int j = 0; j < G1[cur].size(); j++) {
      int x = G1[cur][j].id, w = G1[cur][j].w;
      if (dis1[cur] < dis1[x] - w) {
        dis1[x] = dis1[cur] + w;
        node tmp = {x , dis1[x]};
        pq1.push(tmp);
      }
    }
  }
}
signed main() {
  int m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].push_back(node{v, w});
    G1[v].push_back(node{u , w});
  }
  djikstra(1);
  djikstra1(1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dis1[i] + dis[i];
  }
  cout<<ans;
  return 0;
}