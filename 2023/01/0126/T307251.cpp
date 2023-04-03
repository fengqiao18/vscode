#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 5;
int a[N], b[N], dis[N];
struct node {
  int id, dis;
  inline bool operator<(const node &x) const {
    return dis > x.dis;
  }
};
vector<int> e[N];
priority_queue<node> q;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= k; i++) {
    cin >> b[i];
  }
  fill(dis + 1, dis + n + 1, N);
  dis[1] = (a[1] == b[1]);
  node cur = {1, dis[1]};
  q.push(cur);
  while (!q.empty()) {
    cur = q.top();
    q.pop();
    int u = cur.id;
    for (int v : e[u]) {
      if (dis[v] > dis[u] + (b[dis[u] + 1] == a[v])) {
        dis[v] = dis[u] + (b[dis[u] + 1] == a[v]);
        q.push(node{v, dis[v]});
      }
    }
  }
  if (dis[n] >= k) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}