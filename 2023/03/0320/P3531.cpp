#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int M = 305;
vector<int> id[M];
int num[N], cnt[M];
int tree[N];
int n;
string a, b;
int lowbit(int x) {
  return x & -x;
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
int main() {
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    id[b[i]].push_back(i + 1);
  }
  for (int i = 0; i < n; i++) {
    num[i + 1] = id[a[i]][cnt[a[i]]];
    cnt[a[i]]++;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += i - 1 - query(num[i]);
    update(num[i], 1);
  }
  cout << ans;
  return 0;
}