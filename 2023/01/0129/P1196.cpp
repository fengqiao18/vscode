#include <bits/stdc++.h>
using namespace std;
const int N = 30005;
int fa[N], sz[N], len[N];
int find(int x) {
  if (fa[x] == x) {
    return x;
  }
  int tmp = find(fa[x]);
  len[x] += len[fa[x]];
  return fa[x] = tmp;
}
void unionn(int x, int y) {
  x = find(x), y = find(y);
  fa[x] = y;
  len[x] += sz[y];
  sz[y] += sz[x], sz[x] = 0;
  return;
}
int main() {
  // freopen("1.in" , "r" , stdin);
  int t;
  cin >> t;
  for (int i = 1; i <= 30000; i++) {
    fa[i] = i, len[i] = 0, sz[i] = 1;
  }
  while (t--) {
    char c;
    int x, y;
    cin >> c >> x >> y;
    if (c == 'M') {
      unionn(x, y);
    } else {
      if (find(x) != find(y)) {
        cout << "-1" << endl;
      } else {
        cout << abs(len[x] - len[y]) - 1 << endl;
      }
    }
  }
  return 0;
}
