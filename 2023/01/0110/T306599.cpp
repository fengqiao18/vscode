#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int fa[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    cin >> x >> y;
    fa[y] = x;
  }
  int p;
  cin >> p;
  cout << fa[p] << endl;
  for (int i = 1; i <= n; i++) {
    if (i != p && fa[i] == fa[p]) {
      cout << i << " ";
    }
  }
  return 0;
}