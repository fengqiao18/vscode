#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t, n;
string s[3];
bool dfs(int x, int y, int xx) {
  if (x == 1 && y == 0) {
    return 1;
  }
  if (y == 0) {
    return 0;
  }
  if (s[x][y] <= '2') {
    if (x == xx) {
      return dfs(x, y - 1, x);
    } else {
      return 0;
    }
  } else {
    if (x == xx) {
      return dfs(x % 2 + 1, y, x);
    } else {
      return dfs(x, y - 1, x);
    }
  }
  return 0;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> s[1] >> s[2];
    s[1] = '*' + s[1], s[2] = '*' + s[2];
    if (!dfs(2, n, 2)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}