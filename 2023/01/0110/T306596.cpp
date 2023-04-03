#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int fa[N];
int p;
inline int find(int x) {
  if (fa[x] == x) {
    return x;
  }
  if (x == p) {
    return -1e9;
  }
  return find(fa[x]);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    cin >> x >> y;
    fa[y] = x;
  }
  cin >> p;
  for (int i = 1; i <= n; i++) {
    if (find(i) == -1e9) {
      cout << i << " ";
    }
  }
  return 0;
}