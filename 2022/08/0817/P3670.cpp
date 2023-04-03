#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 55;
int a[N][M], b[N][M];
int ans = 0;
int f(char c) {
  if (c == 'T')
    return 1;
  else if (c == 'A')
    return 2;
  return c == 'C' ? 3 : 4;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      a[i][j] = f(c);
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      b[i][j] = f(c);
    }
  for (int i = 1; i <= m; i++)
    for (int j = i + 1; j <= m; j++)
      for (int k = j + 1; k <= m; k++) {
        bool flag = 1 , tmp[5][5][5] = {0};
        for (int l = 1; l <= n; l++)
          tmp[a[l][i]][a[l][j]][a[l][k]] = 1;
        for (int l = 1; l <= n; l++)
          if (tmp[b[l][i]][b[l][j]][b[l][k]]) {
            flag = 0;
            break;
          }
        if (flag)
          ans++;
      }
  cout << ans;
  return 0;
}