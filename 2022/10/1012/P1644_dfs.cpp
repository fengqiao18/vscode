#include <iostream>
using namespace std;
const int dx[] = {0 , 1, 2, 2, 1};
const int dy[] = {0 , 2, 1, -1, -2};
int n, m, ans;
void dfs(int x, int y) {
  if (x == m && y == n) {
    ans++;
    return;
  }
  for (int i = 1; i <= 4; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    if (xx >= 0 && xx <= m && yy >= 0 && yy <= n)
      dfs(xx, yy);
  }
  return ;
}
int main() {
  cin >> n >> m;
  dfs(0, 0);
  cout << ans;
  return 0;
}