#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int s[5], a[N][5];
int Left, Right, mini;
void dfs(int x, int y) {
  if (x == s[y] + 1) {
    mini = min(mini, max(Left, Right));
    return;
  }
  Left += a[x][y];
  dfs(x + 1, y);
  Left -= a[x][y];
  Right += a[x][y];
  dfs(x + 1, y);
  Right -= a[x][y];
  return;
}
int helper(int i) {
  for (int j = 1; j <= s[i]; j++) {
    cin >> a[j][i];
  }
  Left = Right = 0;
  mini = 1e9;
  dfs(1, i);
  return mini;
}
int main() {
  int ans;
  for (int i = 1; i <= 4; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= 4; i++) {
    ans += helper(i);
  }
  cout << ans;
  return 0;
}