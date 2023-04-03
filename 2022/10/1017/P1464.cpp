#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 25;
int dp[N][N][N];
int w(int a, int b, int c) {
  if (a < 1 || b < 1 || c < 1) {
    return 1;
  }
  if (a > 20 || b > 20 || c > 20) {
    return w(20, 20, 20);
  }
  if (dp[a][b][c] != -1) {
    return dp[a][b][c];
  }
  if (a < b && b < c) {
    return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
  }
  return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
signed main() {
  int a, b, c;
  while (cin >> a >> b >> c) {
    memset(dp, -1, sizeof(dp));
    if (a == -1 && a == b && b == c) {
      return 0;
    }
    cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
  }
  return 0;
}
/*
w(1, 1, 1) = 2
w(2, 2, 2) = 4
*/