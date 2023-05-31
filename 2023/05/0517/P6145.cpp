#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
struct E {
  int id, w;
};
vector<E> G[N];
int dis[N], cnt[N] , s[N];
bool vis[N];
int n;
bool spfa(int s) {
  memset(vis, 0, sizeof(vis));
  priority_queue<int> pq;
  pq.push(s);
  for (int i = 1; i <= n; i++) {
    dis[i] = -1e9;
  }
  dis[s] = 0;
  while (!pq.empty()) {
    int tmp = pq.top();
    pq.pop();
    vis[tmp] = 0;
    for (int i = 0; i < G[tmp].size(); i++) {
      int nxt = G[tmp][i].id, w = G[tmp][i].w;
      if (dis[tmp] + w > dis[nxt]) {
        dis[nxt] = dis[tmp] + w;
        if (vis[nxt] == 0) {
          vis[nxt] = 1;
          pq.push(nxt);
          cnt[nxt] = cnt[tmp] + 1;
          if (cnt[nxt] > n) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}
signed main() {
  int m , c;
  cin >> n >> m >> c;
  for(int i = 1 ; i <= n ; i++){
    cin>>s[i];
  }
  for (int i = 1; i <= c; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    G[x].push_back({y, w});
  }
  for (int i = 1; i <= n; i++) {
    G[0].push_back({i, s[i]});
  }
  if (spfa(0) == 1) {
    cout << "NO";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cout << dis[i] << "\n";
  }
  return 0;
}