#include <bits/stdc++.h>
using namespace std;
const int N = 205;
struct node {
  int ai, bi, ci;
};
node num[N];
int dp[N][N];
bool path[N][N][N];
inline void print(int i, int j, int k) {
  if (i == 1) {
    if (path[i][j][k] == true) {
      cout << i << " ";
    }
    return;
  }
  if (path[i][j][k] == true) {
    print(i - 1, j - num[i].ai, k - num[i].bi);
    cout << i << " ";
  } else {
    print(i - 1, j, k);
  }
  return;
}
int main() {
  int m, v, n;
  cin >> m >> v >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i].ai >> num[i].bi >> num[i].ci;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= num[i].ai; j--) {
      for (int k = v; k >= num[i].bi; k--) {
        if (dp[j][k] < dp[j - num[i].ai][k - num[i].bi] + num[i].ci) {
          dp[j][k] = dp[j - num[i].ai][k - num[i].bi] + num[i].ci;
          path[i][j][k] = true;
        }
      }
    }
  }
  cout << dp[m][v] << endl;
  print(n, m, v);
  return 0;
}