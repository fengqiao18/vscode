#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = 1e9;
typedef pair<int, int> pii;
int a[N];
queue<int> que[4];
bool cmp(int x, int y) { return x > y; }
pii find_max() { return max(make_pair(que[1].empty() ? -inf : que[1].front(), 1), max(make_pair(que[2].empty() ? -inf : que[2].front(), 2), make_pair(que[3].empty() ? -inf : que[3].front(), 3))); }
int main() {
  int n, m, q, u, v, t;
  cin >> n >> m >> q >> u >> v >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    que[1].push(a[i]);
  }
  for (int i = 0; i < m; i++) {
    pii p = find_max();
    que[p.second].pop();
    long long len = p.first + q * i;
    int lt = len * u / v, rt = len - lt;
    que[2].push(lt - q * (i + 1));
    que[3].push(rt - q * (i + 1));
    if (i % t == t - 1) {
      cout << len << " ";
    }
  }
  cout << endl;
  for (int i = 1; i <= n + m; i++) {
    pii p = find_max();
    que[p.second].pop();
    if (i % t == 0) {
      cout << p.first + q * m << " ";
    }
  }
  return 0;
}
