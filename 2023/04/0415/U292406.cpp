#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  int ans = 1e9;
  for (int i = 1; i <= max(x, y); i++) {
    int cnt = i - 1 + x / i + y / i;
    if (x % i != 0) {
      cnt++;
    }
    if (y % i != 0) {
      cnt++;
    }
    ans = min(ans, cnt);
  }
  cout << ans;
  return 0;
}