#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 55;
int num[130], p[N][M], s[N][M];
int n, m, cnt = 0;
bool check(int i, int j, int k) {
  bool vis[5][5][5] = {0};
  for (int l = 1; l <= n; l++) {
    vis[p[l][i]][p[l][j]][p[l][k]] = 1;
  }
  for (int l = 1; l <= n; l++) {
    if (vis[s[l][i]][s[l][j]][s[l][k]] == 1) {
      return 0;
    }
  }
  return 1;
}
int main() {
  num['A'] = 1, num['G'] = 2, num['T'] = 3, num['C'] = 4;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      p[i][j] = num[c];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      s[i][j] = num[c];
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = i + 1; j <= m; j++) {
      for (int k = j + 1; k <= m; k++) {
        cnt += check(i, j, k) ? 1 : 0;
      }
    }
  }
  cout << cnt;
  return 0;
}