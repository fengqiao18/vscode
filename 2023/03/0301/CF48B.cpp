#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int x[N][N], sum[N][N];
int gets(int i , int j , int x , int y){
  return sum[i][j] - sum[x - 1][j] - sum[i][y - 1] + sum[x - 1][y - 1];
}
int main() {
  int n, m, a, b;
  int mini = 1e9;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> x[i][j];
      sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + x[i][j];
    }
  }
  cin >> a >> b;
  for (int x = 1; x + a - 1 <= n; x++) {
    for (int y = 1; y + b - 1 <= m; y++) {
      int i = x + a - 1, j = y + b - 1;
      mini = min(mini, gets(i , j , x , y));
    }
  }
  for (int x = 1; x + b - 1 <= n; x++) {
    for (int y = 1; y + a - 1 <= m; y++) {
      int i = x + b - 1, j = y + a - 1;
      mini = min(mini, gets(i , j , x , y));
    }
  }
  cout << mini;
  return 0;
}