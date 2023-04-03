#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int a[N], tmp[N];
bool vis[N] = {0};
int n, k, cnt = 0;
int abso(int x) { return x >= 0 ? x : -x; }
bool check() {
  tmp[n + 1] = tmp[1];
  for (int i = 1; i <= n; i++) {
    if (abso(tmp[i] - tmp[i + 1]) > k) {
      return 0;
    }
  }
  return 1;
}
// void print() {
//   for (int i = 1; i <= n; i++) {
//     cout << tmp[i] << " ";
//   }
//   cout << endl;
// }
void dfs(int cur) {
  if (cur == n + 1) {
    cnt += check();
    // cout << check() << " ";
    // print();
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      vis[i] = 1;
      tmp[cur] = a[i];
      dfs(cur + 1);
      vis[i] = 0;
    }
  }
  return;
}
int main() {
  // freopen("ball.in", "r", stdin);
  // freopen("ball.out", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dfs(1);
  cout << cnt / n;
  return 0;
}
/*
4 10
2
16
6
10
*/