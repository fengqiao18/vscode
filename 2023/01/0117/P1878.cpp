#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
bool vis[N], f[N];
int n, q[N], cnt;
string s;
struct node {
  int x, y, cnt;
  friend bool operator<(node a, node b) {
    if (a.cnt == b.cnt) {
      return a.x > b.x;
    } else {
      return a.cnt > b.cnt;
    }
  }
};
pair<int, int> ans[N];
priority_queue<node> pq;
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    f[i + 1] = s[i] == 'B';
    cin >> q[i + 1];
  }
  for (int i = 1; i < n; i++) {
    if (f[i] != f[i + 1]) {
      pq.push((node){i, i + 1, abs(q[i] - q[i + 1])});
    }
  }
  while (!pq.empty()) {
    int x = pq.top().x, y = pq.top().y;
    pq.pop();
    if (!vis[x] && !vis[y]) {
      vis[x] = vis[y] = 1;
      cnt++;
      ans[cnt].first = x;
      ans[cnt].second = y;
      while (x > 0 && vis[x]) {
        x--;
      }
      while (y <= n && vis[y]) {
        y++;
      }
      if (x > 0 && y <= n && f[x] != f[y]) {
        pq.push((node){x, y, abs(q[x] - q[y])});
      }
    }
  }
  cout << cnt << endl;
  for (int i = 1; i <= cnt; i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
