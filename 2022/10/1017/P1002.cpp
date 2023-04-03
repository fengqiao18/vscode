#include <bits/stdc++.h>
using namespace std;
const int N = 25;
const int dx[] = {0, -1, 1, 2, 2, 1, -1, -2, -2};
const int dy[] = {0, -2, -2, -1, 1, 2, 2, 1, -1};
int endx, endy, mx, my;
long long dp[N][N];
long long dfs(int x, int y) {
  if (x < 1 || y < 1 || x > endx || y > endy) {
    return 0;
  }
  if (dp[x][y] == -1) {
    return 0;
  }
  if (dp[x][y] > 0) {
    return dp[x][y];
  }
  if (x == 1 && y == 1) {
    return dp[x][y] = 1;
  }
  return dp[x][y] = dfs(x, y - 1) + dfs(x - 1, y);
}
int main() {
  cin >> endx >> endy >> mx >> my;
  endx++, endy++, mx++, my++;
  for (int i = 0; i <= 8; i++) {
    int xx = mx + dx[i], yy = my + dy[i];
    if (xx >= 1 && xx <= endx && yy >= 1 && yy <= endy) {
      dp[xx][yy] = -1;
    }
  }
  cout << dfs(endx, endy);
  return 0;
}