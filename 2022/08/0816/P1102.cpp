#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll a[N], ans = 0;
int main() {
  ll n, c;
  cin >> n >> c;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + 1 + n);
  ll lt = 1, rt = 0;
  while (rt < n) {
    while (a[rt] - a[lt] < c && rt < n)
      rt++;
    while (a[rt] - a[lt] > c && lt < rt)
      lt++;
    if (a[rt] - a[lt] == c) {
      ll zuo = 1, you = 1;
      while (a[lt] == a[lt + 1] && lt < n)
        zuo++, lt++;
      while (a[rt] == a[rt + 1] && rt < n)
        you++, rt++;
      lt++;
      ans += zuo * you;
    }
  }
  cout << ans;
  return 0;
}