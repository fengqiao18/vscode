#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, -1, 1, 0, 0};

int a[N][N], ans[N][N];
int n, m, group = 1;
bool vis[N][N];
int cnt[N * N];

void dfs(int x, int y, int last) {
  if (x > n || x < 1 || y > n || y < 1 || vis[x][y] == 1 || a[x][y] == last) {
    return;
  }
  vis[x][y] = 1;
  cnt[0]++;
  for (int i = 1; i <= 4; i++)
    dfs(x + dx[i], y + dy[i], a[x][y]);
  ans[x][y] = group;
  cnt[group] = max(cnt[group], cnt[0]);
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (vis[i][j] == 0) {
        dfs(i, j, a[i][j] + 1);
        cnt[0] = 0;
        group++;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    cout << cnt[ans[x][y]] << endl;
  }
  return 0;
}