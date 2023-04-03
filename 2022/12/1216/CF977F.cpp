#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], ans[N];
map<int, int> m;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int tmp = m[a[i] - 1];
    if (tmp != 0) {
      ans[i] = ans[tmp] + 1;
    } else {
      ans[i] = 1;
    }
    m[a[i]] = i;
  }
  int vis, len = -1e9;
  for (int i = 1; i <= n; i++) {
    if (ans[i] > len) {
      len = ans[i], vis = a[i];
    }
  }
  cout << len << endl;
  int num = vis - len + 1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == num) {
      cout << i << " ";
      num++;
    }
  }
  return 0;
}