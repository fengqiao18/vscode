#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, ans, maxx;
int a[N], dp[N], f[N];
int prime[N], tot;
bool v[N];
vector<int> fac[N];
void init() {
  for (int i = 2; i <= maxx; i++) {
    if (!v[i]){
      prime[++tot] = i;
    }
    for (int j = 1; j <= tot && i * prime[j] <= maxx; j++) {
      v[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        break;
      }
    }
  }
}
int main() {
  cin>>n;
  for (int i = 1; i <= n; i++) {
    cin>>a[i];
    dp[i] = 1;
    maxx = max(maxx, a[i]);
  }
  init();
  for (int i = 1; i <= tot; i++)
    for (int j = prime[i]; j <= maxx; j += prime[i])
      fac[j].push_back(prime[i]);
  for (int i = 1; i <= n; i++) {
    int tmp = 0;
    for (int j = 0; j < fac[a[i]].size(); j++)
      tmp = max(tmp, f[fac[a[i]][j]]);
    dp[i] = max(dp[i], tmp + 1);
    for (int j = 0; j < fac[a[i]].size(); j++)
      f[fac[a[i]][j]] = max(f[fac[a[i]][j]], dp[i]);
  }
  for (int i = 1; i <= n; i++)
    ans = max(ans, dp[i]);
  printf("%d\n", ans);
  return 0;
}