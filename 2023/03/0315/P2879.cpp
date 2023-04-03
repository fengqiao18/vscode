#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int diff[N], a[N];
bool vis[N][N];
int main() {
  int r, n, h, p;
  cin >> n >> p >> h >> r;
  diff[1] = h;
  for (int i = 1; i <= r; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
      swap(a, b);
    }
    if (vis[a][b]) {
      continue;
    }
    vis[a][b] = 1;
    diff[a + 1]--;
    diff[b]++;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + diff[i];
    cout << a[i] << endl;
  }
  return 0;
}