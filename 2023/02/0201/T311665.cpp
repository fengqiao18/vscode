#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, m;
int a[N], cnt[N];
vector<int> g[N];
int f(int x) {
  queue<int> q[2];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < g[i].size(); j++) {
      cnt[g[i][j]]++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!cnt[i]) {
      q[a[i]].push(i);
    }
  }
  int ans = 0;
  while (q[0].size() + q[1].size() > 0) {
    if (q[x].empty()) {
      x = 1 - x;
      ans++;
    }
    int tmp = q[x].front();
    q[x].pop();
    for (int i = 0; i < g[tmp].size(); i++) {
      int cur = g[tmp][i];
      cnt[cur]--;
      if (cnt[cur] == 0) {
        q[a[cur]].push(cur);
      }
    }
  }
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x - 1].push_back(y - 1);
  }
  cout << min(f(0), f(1));
  return 0;
}
