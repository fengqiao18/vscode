#include <bits/stdc++.h>
using namespace std;
int main() {
  // freopen("sing.in", "r", stdin);
  // freopen("sing.out", "w", stdout);
  int k, mini = 1e9, vis;
  string s, t;
  cin >> k >> s >> t;
  for (int i = 0; i < s.size(); i++) {
    int cnt = 0, flag = 1, ans = 0;
    for (int j = 0; j < t.size(); j++) {
      if (s[i + j] != t[j]) {
        cnt++, ans++;
      } else {
        if (cnt >= k) {
          flag = 0;
          break;
        }
        cnt = 0;
      }
      if (cnt >= k) {
        flag = 0;
        break;
      }
    }
    if (flag && ans < mini) {
      mini = ans;
      vis = i;
    }
  }
  cout << vis + 1;
  return 0;
}