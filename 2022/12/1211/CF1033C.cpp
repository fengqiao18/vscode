#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int a[N], pos[N], ans[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    pos[a[i]] = i;
  }
  for (int i = n; i >= 1; i--) {
    int ps = pos[i], j = ps;
    ans[ps] = 0;
    while (j - a[ps] > 0) j -= a[ps];
    for (; j <= n; j += a[ps]) {
      if (!(a[ps] < a[j])) {
        continue;
      }
      if (ans[j] == 0) {
        ans[ps] = 1;
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i]) {
      cout << 'A';
    } else {
      cout << 'B';
    }
  }
  return 0;
}