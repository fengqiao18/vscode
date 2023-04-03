#include <bits/stdc++.h>
using namespace std;
const int p = 1e9 + 7;
const int N = 1e6 + 5;
int a[N];
int main() {
  long long n, ans = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    if (a[i] - i + 1 <= 0) {
      cout << -1;
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    ans = (ans * (a[i] - i + 1)) % p;
  }
  cout << ans;
  return 0;
}
