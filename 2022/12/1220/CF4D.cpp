#include <bits/stdc++.h>
using namespace std;
const int N = 5015;
struct node {
  int w, h, id;
};
node a[N];
bool cmp(node a, node b) {
  return a.w < b.w;
}
int dp[N], ps[N], as[N];
int main() {
  int n, w, h;
  int cnt = 0;
  cin >> n >> w >> h;
  for (int i = 1; i <= n; i++) {
    int _w, _h;
    cin >> _w >> _h;
    if (_w > w && _h > h) {
      a[++cnt] = (node){_w, _h, i};
    }
  }
  if (cnt == 0) {
    cout << 0;
    return 0;
  }
  int pos, ans = -1e9;
  sort(a + 1, a + cnt + 1, cmp);
  for (int i = 1; i <= cnt; i++) {
    for (int j = 0; j < i; j++) {
      if (a[j].h < a[i].h && a[j].w < a[i].w) {
        if (dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          ps[i] = j;
        }
      }
    }
    if (dp[i] > ans) {
      ans = dp[i];
      pos = i;
    }
  }
  cout << ans << endl;
  int k = 0;
  while (pos != 0) {
    as[++k] = a[pos].id;
    pos = ps[pos];
  }
  for (int i = k; i >= 1; i--) {
    cout << as[i] << " ";
  }
  return 0;
}