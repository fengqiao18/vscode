#include <bits/stdc++.h>
#define inf 1e9
using namespace std;
int n, ans = inf;
long long f(int x) {
  return x * x * x * x;
}
void dfs(int sum, int last, int cur) {
  if (sum > n || cur > ans) {
    return;
  } else if (sum == n) {
    ans = min(ans, cur);
  }
  int i = last;
  for (; f(i) <= n - sum; i++) {
  }
  for (; i >= last; i--) {
    dfs(sum + f(i), max(i, last), cur + 1);
  }
  return;
}
int main() {
  cin >> n;
  dfs(0, 1, 0);
  cout << ans;
  return 0;
}