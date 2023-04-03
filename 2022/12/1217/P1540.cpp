#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int m, n, cnt, x;
bool vis[1005];
int main() {
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (!vis[x]) {
      if (q.size() >= m) {
        vis[q.front()] = 0;
        q.pop();
      }
      q.push(x);
      vis[x] = 1;
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}