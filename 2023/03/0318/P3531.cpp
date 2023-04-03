#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int cnt[26][N], a[N], d[26];
int tree[N];
int n;
int lowbit(int x) {
  return x & (-x);
}
void update(int x, int val) {
  while (x <= n) {
    tree[x] += val;
    x += lowbit(x);
  }
  return;
}
int query(int x) {
  int sum = 0;
  while (x != 0) {
    sum += tree[x];
    x -= lowbit(x);
  }
  return sum;
}
signed main() {
  int ans = 0;
  string s, s1;
  cin >> n >> s >> s1;
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'A'][++cnt[s[i] - 'A'][0]] = i;
  }
  for (int i = 0; i < n; i++) {
    a[i + 1] = cnt[s1[i] - 'A'][++d[s1[i] - 'A']] + 1;
  }
  for (int i = 1; i <= n; i++) {
    ans += query(n) - query(a[i] - 1);
    update(a[i], 1);
  }
  cout << ans;
  return 0;
}