#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int diff[N], a[N];
bool vis[N];
int lt = 1e9, rt = -1e9;
int f(bool d) {
  int maxi = -1e9, len = 0;
  for (int i = lt; i <= rt; i++) {
    if (vis[i] == d) {
      len++;
    } else {
      maxi = max(maxi, len);
      len = 0;
    }
  }
  maxi = max(maxi, len);
  return maxi;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    r--, lt = min(lt, l), rt = max(rt, r);
    diff[l]++, diff[r+1]--;
  }
  a[0] = diff[0];
  vis[0] = a[0] > 0;
  for (int i = 1; i <= 1e6; i++) {
    a[i] = a[i - 1] + diff[i];
    vis[i] = a[i] > 0;
  }
  cout << f(1) << " " << f(0);
  return 0;
}