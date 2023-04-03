#include <bits/stdc++.h>
using namespace std;
int a[15][25];
int main() {
  int k, n, cnt = 0;
  cin >> k >> n;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      bool f = 0, flag = 0, vis = 1;
      for (int l = 1; l <= k; l++) {
        int v1, v2;
        for (int m = 1; m <= n; m++)
          if (a[l][m] == i) {
            v1 = m;
            break;
          }
        for (int m = 1; m <= n; m++)
          if (a[l][m] == j) {
            v2 = m;
            break;
          }
        if (!f) {
          f = 1;
          flag = v1 < v2 ? 1 : 0;
        } else {
          if ((flag && v1 > v2) || (!flag && v1 < v2)) {
            vis = 0;
          }
        }
      }
      if (vis)
        cnt++;
    }
  }
  cout << cnt;
  return 0;
}