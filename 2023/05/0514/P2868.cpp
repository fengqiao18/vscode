#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005;
const double eps = 1e-6;
int n, m, cnt[N], u[N], v[N];
double dis[N], f[N], w[N];
bool vis[N];
struct node {
  int id;
  double w;
};
vector<node> nbr[N];
bool spfa() {
  queue<int> q;
  memset(vis, 0, sizeof(vis));
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) {
    dis[i] = 0;
    q.push(i);
    vis[i] = 1;
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    vis[cur] = 0;
    for (int i = 0; i < nbr[cur].size(); i++) {
      int nxt = nbr[cur][i].id;
      double w = nbr[cur][i].w;
      if (dis[cur] + w < dis[nxt]) {
        dis[nxt] = dis[cur] + w;
        cnt[nxt] = cnt[cur] + 1;
        if (cnt[nxt] >= n){
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
  for (int i = 1; i <= n; i++){
    nbr[i].clear();
  }
  for (int i = 1; i <= m; i++){
    nbr[u[i]].push_back((node){v[i], w[i] * mid - f[u[i]]});
  }
  return spfa();
}
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> f[i];
  for (int i = 1; i <= m; i++)
    cin >> u[i] >> v[i] >> w[i];
  double lt = 0, rt = 1000;
  while (lt + eps < rt) {
    double mid = (lt + rt) / 2;
    if (check(mid)){
      lt = mid;
    }
    else{
      rt = mid;
    }
  }
  cout << fixed << setprecision(2) << lt << endl;
  return 0;
}