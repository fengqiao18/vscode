#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 150005;
struct node {
  ll x, y;
};
node a[N];
bool cmp(node a, node b) {
  return a.y < b.y;
}
priority_queue<ll> q;
int main() {
  ll n;
  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  sort(a + 1, a + n + 1, cmp);
  ll cnt = 0, ans = 0;
  for (ll i = 1; i <= n; ++i) {
    if (cnt + a[i].x <= a[i].y) {
      ans++;
      cnt += a[i].x;
      q.push(a[i].x);
    } else if (a[i].x < q.top()) {
      cnt = cnt - q.top() + a[i].x;
      q.pop();
      q.push(a[i].x);
    }
  }
  cout << ans;
  return 0;
}