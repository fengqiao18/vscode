#include <bits/stdc++.h>
using namespace std;

const int N = 205;
const int dx[] = {0, 1, -1};

struct node {
  int x, step;
};
int n, a, b;
int f[N];

int bfs(int x, int y) {
  queue<node> q;
  bool vis[N] = {0};
  node cur = {x, 0};
  q.push(cur);
  vis[x] = 1;
  while (!q.empty()) {
    cur = q.front();
    q.pop();
    if (cur.x == y) {
      return cur.step;
    }
    for (int i = 1; i <= 2; i++) {
      int xx = cur.x + dx[i] * f[cur.x];
      if (xx >= 1 && xx <= 200 && !vis[xx]) {
        node tmp = {xx, cur.step + 1};
        q.push(tmp);
        vis[xx] = 1;
      }
    }
  }
  return -1;
}

int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
  }
  cout << bfs(a, b);
  return 0;
}