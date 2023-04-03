#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int p = 1e9 + 7;
int dp[N], sum[N];
vector<pair<int, int> > a;
vector<int> b;
inline void upt(int t, int s) { a.push_back(make_pair(t, s)), b.push_back(t); }
inline int fd(int k) { return lower_bound(b.begin(), b.end(), k) - b.begin(); }
int main() {
  int n, m;
  cin >> n >> m;
  upt(0, 0);
  for (int i = 1; i <= m; i++) {
    int s, t;
    cin >> s >> t;
    upt(t, s);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 1; i <= m; i++) {
    if (a[i].second == 0) {
      dp[i] = 1;
    }
    int s = fd(a[i].second) , t = fd(a[i].first);
    dp[i] = (dp[i] + sum[t] - sum[s] + p) % p;
    sum[i + 1] = (sum[i] + dp[i]) % p;
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = (ans + (a[i].first == n ? dp[i] : 0)) % p;
  }
  cout << ans;
  return 0;
}
