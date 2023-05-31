#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
double f[N], w[N], dis[N];
int u[N], v[N], cnt[N];
bool vis[N];
int n, m;
struct node {
  int x;
  double w;
};
vector<node> G[N];
bool spfa() {
  queue<int> q;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) {
    q.push(i);
    vis[i] = 1;
    dis[i] = 0;
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    vis[cur] = 0;
    for (int i = 0; i < G[cur].size(); i++) {
      int nxt = G[cur][i].x;
      double w = G[cur][i].w;
      if (dis[nxt] > dis[cur] + w) {
        dis[nxt] = dis[cur] + w;
        cnt[nxt] = cnt[cur] + 1;
        if (cnt[nxt] >= n) {
          return 1;
        }
        if (vis[nxt] == 0) {
          q.push(nxt);
          vis[nxt] = 1;
        }
      }
    }
  }
  return 0;
}
bool check(double mid) {
  for (int i = 1; i <= m; i++) {
    G[i].clear();
  }
  for (int i = 1; i <= m; i++) {
    G[u[i]].push_back((node){v[i], mid * w[i] - f[u[i]]});
  }
  return spfa();
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> u[i] >> v[i] >> w[i];
  }
  double lt = 0, rt = 1000;
  while (lt + 1e-8 < rt) {
    double mid = (lt + rt) / 2;
    if (check(mid)) {
      lt = mid;
    } else {
      rt = mid;
    }
  }
  cout << fixed << setprecision(2) << lt;
  return 0;
}