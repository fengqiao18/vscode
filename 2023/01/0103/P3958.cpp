#include <bits/stdc++.h>
#define int long long
#define db double
using namespace std;
const int N = 1e3 + 5;
int fa[N];
struct node {
  db x, y, z;
};
node a[N];
inline db f(db x) { return x * x; }  // 平方
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); };
inline void unionn(int x, int y) { x = find(x), y = find(y), fa[x] = x != y ? y : fa[x]; }
inline db dis(int i, int j) { return sqrt(f(a[i].x - a[j].x) + f(a[i].y - a[j].y) + f(a[i].z - a[j].z)); }  // 距离
inline bool helper(int n, db h, db r) {
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y >> a[i].z;
  }
  for (int i = 1; i <= n + 2; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (dis(i, j) <= 2 * r) {  // 相接
        unionn(i, j);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (a[i].z <= r) {  // 下表面
      unionn(i, n + 1);
    }
    if (a[i].z + r >= h) {  // 上表面
      unionn(i, n + 2);
    }
  }
  return find(n + 1) == find(n + 2);
}
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    db h, r;
    cin >> n >> h >> r;
    cout << (helper(n, h, r) ? "Yes" : "No") << endl;
  }
  return 0;
}