#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int w[N], t[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  int tl = 0;
  int cnt = 0;
  while (cnt < m) {
    ++tl;
    if (tl > n) {
      cout << "no answer";
      return 0;
    }
    if (!t[w[tl]]) {
      ++cnt;
    }
    ++t[w[tl]];
  }
  int ans = tl;
  for (int i = 1; i <= n && tl <= n; i++) {
    --t[w[i]];
    if (t[w[i]] > 0) {
      continue;
    }
    ans = min(ans, tl - i + 1);
    --cnt;
    while (cnt != m) {
      ++tl;
      if (tl > n) {
        break;
      }
      if (!t[w[tl]]) {
        cnt++;
        ans = min(ans, tl - i);
      }
      ++t[w[tl]];
    }
  }
  cout << ans;
  return 0;
}