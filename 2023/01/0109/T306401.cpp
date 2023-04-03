#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int ans[N];
int cnt[N], tmp[N];
int n;
namespace lyt {
inline int f(int x) {
  if (x == 0) {
    return n;
  }
  return x == n + 1 ? 1 : x;
}
inline void update() {
  for (int i = 1; i <= n; i++) {
    cnt[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cnt[f(i + tmp[i])]++;
  }
  int count = 0;
  for (int i = 1; i <= n; i++) {
    count += cnt[i] == 0;
  }
  ans[count]++;
  return;
}
inline void dfs(int cur) {
  if (cur == n + 1) {
    update();
    return;
  }
  tmp[cur] = 1;
  dfs(cur + 1);
  tmp[cur] = -1;
  dfs(cur + 1);
  return;
}
}  // namespace lyt
using namespace lyt;
int main() {
  cin >> n;
  dfs(1);
  for (int i = 0; i <= n; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}