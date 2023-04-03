#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int fa[N];
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
inline bool same(int x, int y) { return find(x) == find(y); }
inline void init(int n) {
  for (int i = 1; i <= 3 * n; i++) {
    fa[i] = i;
  }
  return;
}
int main() {
  int n, m, cnt = 0;
  cin >> n >> m;
  init(n);
  while (m--) {
    int opt, x, y;
    cin >> opt >> x >> y;
    if (x > n || y > n) {  // 假话2
      cnt++;
      continue;
    }
    if (opt == 1) {
      if (same(x + n, y) || same(x, y + n)) {  // 假话1/3
        cnt++;
        continue;
      }
      fa[find(x)] = find(y);                  // 同类
      fa[find(x + n)] = find(y + n);          // 同类
      fa[find(x + n + n)] = find(y + n + n);  // 同类
    } else {
      if (same(x, y) || same(x, y + n)) {  // 假话1/3
        cnt++;
        continue;
      }
      fa[find(x)] = find(y + n + n);      // y吃y'吃y''(x同类)
      fa[find(x + n)] = find(y);          // x吃x'(y同类)
      fa[find(x + n + n)] = find(y + n);  // x吃x'吃x''(y吃y''同类)-->x=A,y=B,x+n+n=C,y+n=C
    }
  }
  cout << cnt;
  return 0;
}