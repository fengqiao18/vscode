#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int fa[N], vis[N], cnt[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    fa[y] = x;
    vis[x] = vis[y] = 1;
    cnt[x]++;
  }
  int root, p, maxi = -1;
  for (int i = 1; i <= 1000; i++) {
    if (!fa[i] && vis[i]) {
      root = i;
      break;
    }
  }
  for (int i = 1; i <= 1000; i++) {
    if (cnt[i] > maxi) {
      maxi = cnt[i];
      p = i;
    }
  }
  cout << root << "\n"
       << p << "\n";
  for (int i = 1; i <= 1000; i++) {
    if (fa[i] == p) {
      cout << i << " ";
    }
  }
  return 0;
}