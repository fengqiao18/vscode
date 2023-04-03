#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll helper(int n) {
  ll a[N], cnt[N] = {0};
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < i) {
      cnt[a[i]]++;
    }
  }
  for (int i = n; i >= 1; i--) {
    cnt[i] += cnt[i + 1];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] < i) {
      ans += cnt[i + 1];
    }
  }
  return ans;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", helper(n));
  }
  return 0;
}