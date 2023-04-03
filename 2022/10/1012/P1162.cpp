#include <bits/stdc++.h>
using namespace std;

const int N = 35;
const int dx[] = {0, 0, 0, -1, 1};
const int dy[] = {0, -1, 1, 0, 0};

int n, a[N][N];
bool vis[N][N];

void dfs(int x, int y) {
  if (x > n || x < 1 || y > n || y < 1 || a[x][y] == 1 || vis[x][y] == 1)
    return;
  vis[x][y] = 1;
  a[x][y] = 2;
  for (int i = 1; i <= 4; i++) {
    dfs(x + dx[i], y + dy[i]);
  }
  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == 0 && a[i - 1][j] == 1 && a[i][j - 1] == 1) {
        dfs(i, j);
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
          }
          cout << endl;
        }
        return 0;
      }
    }
  }
  return 0;
}