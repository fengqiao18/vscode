#include <bits/stdc++.h>
using namespace std;
int cnt[6], a[4] = {6, 2, 4, 8};
int main() {
  int n, ans = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int tmp = i;
    while (tmp % 2 == 0) {
      cnt[2]++;
      tmp /= 2;
    }
    while (tmp % 5 == 0) {
      cnt[5]++;
      tmp /= 5;
    }
    ans = (ans * tmp) % 10;
  }
  int tmp = cnt[2] - cnt[5];
  // cout << tmp << " " << ans << endl;
  ans = (ans * a[tmp % 4]) % 10;
  cout << ans;
  return 0;
}