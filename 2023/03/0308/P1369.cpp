#include <bits/stdc++.h>
using namespace std;
const int k = 100;
const int N = 105;
int a[N][N], sum[N][N];
int firstsum(int x, int y, int i, int j) {
  return sum[i][j] - sum[x - 1][j] - sum[i][y - 1] + sum[x - 1][y - 1];
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    a[x][y] = 1;
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= k; j++) {
      sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
    }
  }
  int maxi = 0;
  for (int x = 1; x <= k; x++) {
    for (int y = 1; y <= k; y++) {
      for (int i = x + 1; i <= k; i++) {
        for (int j = y + 1; j <= k; j++) {
          int c = firstsum(x, y, i, j) - firstsum(x + 1, y + 1, i - 1, j - 1);
          maxi = max(maxi, c);
        }
      }
    }
  }
  cout << maxi;
  return 0;
}