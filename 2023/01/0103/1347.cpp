#include <bits/stdc++.h>
using namespace std;
const int N = 4e4 + 5;
int fa[N];
int n, m;
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); };
inline void unionn(int x, int y) { x = find(x), y = find(y), fa[x] = x != y ? y : fa[x]; }
inline int get_id(int x, int y) { return (x - 1) * n + y; }
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n * n; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    int p1, p2;
    char c;
    cin >> x >> y >> c;
    p1 = get_id(x, y);
    if (c == 'D') {
      p2 = get_id(x + 1, y);
    } else {
      p2 = get_id(x, y + 1);
    }
    if (find(p1) == find(p2)) {
      cout << i;
      return 0;
    } else {
      unionn(p1, p2);
    }
  }
  cout << "draw";
  return 0;
}