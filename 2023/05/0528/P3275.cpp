#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, m, dis[N], cnt[N];
bool vis[N];
struct node {
  int to, w;
};
vector<node> g[N];
bool spfa() {
  memset(dis, 0xcf, sizeof(dis));
  queue<int> q;
  q.push(0);
  dis[0] = 0;
  vis[0] = 1;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    vis[cur] = 0;
    for (int i = 0; i < g[cur].size(); i++) {
      int y = g[cur][i].to, w = g[cur][i].w;
      if (dis[cur] + w > dis[y]) {
        dis[y] = dis[cur] + w;
        cnt[y] = cnt[cur] + 1;
        if (cnt[y] >= n + 1) {
          return true;
        }
        if (vis[y] == 0) {
          vis[y] = 1;
          q.push(y);
        }
      }
    }
  }
  return 0;
}
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, a, b;
    cin >> x >> a >> b;
    if (x == 1) {
      g[a].push_back((node){b, 0});
      g[b].push_back((node){a, 0});
    } else if (x == 2) {
      g[a].push_back((node){b, 1});
    } else if (x == 3) {
      g[b].push_back((node){a, 0});
    } else if (x == 4) {
      g[b].push_back((node){a, 1});
    } else {
      g[a].push_back((node){b, 0});
    }
  }
  for (int i = 1; i <= n; i++) {
    g[0].push_back((node){i, 1});
  }
  if (spfa()) {
    cout << "-1";
    return 0;
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += dis[i];
  }
  cout << sum;
  return 0;
}