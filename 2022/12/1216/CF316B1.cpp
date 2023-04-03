#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int a[N], lst[N];
bool vis[N], f[N];
int m, num;
int main() {
  int n, pos;
  cin >> n >> pos;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x != 0) {
      lst[x] = i, vis[i] = 1;
    }
  }
  for (int i = 1, cnt, p; i <= n; i++) {
    if (vis[i] == 1) {
      continue;
    }
    bool flag = 0;
    cnt = 0, p = i;
    while (p != 0) {
      cnt++;
      if (p == pos) {
        num = cnt;
        flag = 1;
        break;
      }
      p = lst[p];
    }
    if (flag) {
      continue;
    }
    a[++m] = cnt;
  }
  f[0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = n; j >= a[i]; j--) {
      if (f[j - a[i]] == 1) {
        f[j] = 1;
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    if (f[i] == 1) {
      cout << i + num << endl;
    }
  }
  return 0;
}