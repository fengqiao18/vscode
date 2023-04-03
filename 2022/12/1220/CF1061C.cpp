#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int p = 1e9 + 7;
int a[N], f[N], mod[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    int top = 0;
    for (int j = 1; j <= sqrt(a[i]); j++) {
      if (a[i] % j != 0) {
        continue;
      }
      mod[++top] = j;
      if (j * j != a[i]) {
        mod[++top] = a[i] / j;
      }
    }
    sort(mod + 1, mod + top + 1);
    for (int j = top; j >= 1; j--){
      f[mod[j]] = (f[mod[j]] + f[mod[j] - 1]) % p;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++){
    ans = (ans + f[i]) % p;
  }
  cout << ans;
  return 0;
}