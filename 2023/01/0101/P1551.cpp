#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int fa[N];
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline void unioun(int x, int y) {
  x = find(x), y = find(y);
  if (x != y) {
    fa[x] = y;
  }
  return;
}
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    unioun(x, y);
  }
  for (int i = 1; i <= q; i++) {
    int x, y;
    cin >> x >> y;
    if (find(x) == find(y)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}