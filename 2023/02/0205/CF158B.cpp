#include <bits/stdc++.h>
using namespace std;
int a[5];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  int ans = a[4] + a[2] / 2;
  if (a[2] % 2 != 0) {
    ans++;
    if (a[1] >= 2) {
      a[1] -= 2;
    } else if (a[1] >= 1) {
      a[1]--;
    }
  }
  if (a[1] == a[3]) {
    ans += a[1];
  } else if (a[1] > a[3]) {
    ans += a[3];
    a[1] -= a[3];
    ans += a[1] / 4;
    if (a[1] % 4 != 0) {
      ans++;
    }
  } else if (a[1] < a[3]) {
    ans += a[3];
  }
  cout << ans;
  return 0;
}
