#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 5e5 + 5;
long long a[N], cnt[M];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  long long ans = 0;
  for (int i = 1; i <= 5e5; i++) {
    for (int j = 2; i * j <= 5e5; j++) {
      ans += cnt[i] * cnt[i * j];
    }
    ans += cnt[i] * (cnt[i] - 1);
  }
  cout << ans;
  return 0;
}