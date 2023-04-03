#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  s = '*' + s;
  for (int i = 1; i <= n - 1; i++) {
    int ans = 0;
    for (int j = 1; j + i <= n; j++) {
      if (s[j] != s[j + i]) {
        ans = j;
      } else {
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
