#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int fa[N];
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void unionn(int x, int y) {
  x = find(x), y = find(y);
  if (x != y) {
    fa[x] = y;
  }
  return;
}
int help(int n, int m) {
  for (int i = 1; i <= n; i++)
    fa[i] = i;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    unionn(x, y);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (fa[i] == i) {
      cnt++;
    }
  }
  return cnt - 1;
}
int main() {
  int n, m;
  while (cin >> n >> m) {
    if (n == 0) {
      return 0;
    }
    cout << help(n, m) << endl;
  }
  return 0;
}