#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, fa[N], ans = 1e9, cnt;
int find(int x) {
  cnt++;
  if (fa[x] == x) {
    return x;
  }
  return find(fa[x]);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= n; i++) {
    cnt = 0;
    int x;
    cin >> x;
    if (find(x) == i) {
      ans = min(ans, cnt);
    } else {
      fa[i] = x;
    }
  }
  cout << ans;
  return 0;
}