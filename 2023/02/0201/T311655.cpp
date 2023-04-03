#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int cnt[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = 0; x != 0; j++, x /= 2) {
      cnt[j] += (x & 1);
    }
  }
  long long ans = 0;
  for (long long i = 0, k = 1; i < 20; i++, k *= 2) {
    ans += k * cnt[i] * (n - cnt[i]);
  }
  cout << ans;
  return 0;
}
