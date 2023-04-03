#include <bits/stdc++.h>
using namespace std;
int ans = 0, n;
bool vis[10];
int fp[25][3];
void f(int cnt) {
  if (cnt > n) {
    ans++;
    return;
  }
  for (int i = 1; i <= 2; i++) {
    if (vis[fp[cnt][i]] == 0) {
      vis[fp[cnt][i]] = 1;
      f(cnt + 1);
      vis[fp[cnt][i]] = 0;
    }
  }
  return;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> fp[i][1] >> fp[i][2];
  f(1);
  cout << ans;
  return 0;
}