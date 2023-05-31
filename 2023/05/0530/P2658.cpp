#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[1005][1005], s[1005][1005], f[250000];
int find(int x) {
  if (f[x] == x) {
    return x;
  }
  return f[x] = find(f[x]);
}
void unionn(int x, int y) {
  x = find(x), y = find(y);
  if (x != y) {
    f[x] = y;
  }
  return;
}
int getid(int x, int y) {
  return (x - 1) * m + y;
}
bool check(int x) {
  for (int i = 1; i <= n * m; i++) {
    f[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int g = getid(i, j), b = getid(i, j + 1), c = getid(i + 1, j);
      if (abs(a[i][j] - a[i][j + 1]) <= x && a[i][j + 1]) {
        unionn(g, b);
      }
      if (abs(a[i][j] - a[i + 1][j]) <= x && a[i + 1][j]) {
        unionn(g, c);
      }
    }
  }
  int ls = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j]) {
        if (ls == 0) {
          int r = find(getid(i, j));
          ls = r;
        } else {
          int r = find(getid(i, j));
          if (ls != r) {
            return 0;
          }
        }
      }
    }
  }
  return 1;
}
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> s[i][j];
    }
  }
  int lt = -1, rt = 1e9 + 1;
  while (lt + 1 < rt) {
    int mid = (lt + rt) / 2;
    if (check(mid)) {
      rt = mid;
    } else {
      lt = mid;
    }
  }
  cout << rt;
  return 0;
}