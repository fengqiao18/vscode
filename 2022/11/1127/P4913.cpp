#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> a[N];
int maxi = -1e9;
void dfs(int cur, int t) {
  maxi = max(maxi, t);
  for (int i = 0; i < a[cur].size(); i++) {
    dfs(a[cur][i], t + 1);
  }
  return;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    if (x) {
      a[i].push_back(x);
    }
    if (y) {
      a[i].push_back(y);
    }
  }
  dfs(1, 1);
  cout << maxi;
  return 0;
}