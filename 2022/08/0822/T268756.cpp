#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 55;
struct node {
  int x, y, t;
};
node e[N];
bool a[M], b[M];
int main() {
  int n, m, d, s;
  cin >> n >> m >> d >> s;
  for (int i = 1; i <= d; i++) {
    cin >> e[i].x >> e[i].y >> e[i].t;
  }
  fill(a, a + 1 + m, 1);
  for (int i = 1; i <= s; i++) {
    int x, t;
    cin >> x >> t;
    fill(b, b + 1 + m, 0);
    for (int j = 1; j <= d; j++) {
      b[e[j].y] |= e[j].t < t && e[j].x == x;
    }
    for (int j = 1; j <= m; j++) {
      a[j] &= b[j];
    }
  }
  fill(b, b + n + 1, 0);
  for (int i = 1; i <= d; i++) {
    b[e[i].x] |= a[e[i].y];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += b[i];
  }
  cout << ans;
  return 0;
}