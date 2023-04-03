#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
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
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int z, x, y;
    cin >> z >> x >> y;
    if (z == 1) {
      unioun(x, y);
    } else if (find(x) == find(y)) {
      cout << "Y\n";
    } else {
      cout << "N\n";
    }
  }
  return 0;
}