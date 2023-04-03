#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int> son[N];
bool vis[N];
int in[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    son[x].push_back(y);
    in[y]++;
    vis[x] = vis[y] = 1;
  }
  int root = -1;
  for (int i = 1; i <= 1000; i++) {
    if (in[i] == 0 && vis[i] == 1) {
      root = i;
      break;
    }
  }
  int maxi = -1e9, p = -1;
  for (int i = 1; i <= 1000; i++) {
    int s = son[i].size();
    if (maxi < s) {
      maxi = s;
      p = i;
    }
  }
  cout << root << "\n"
       << p << "\n";
  sort(son[p].begin(), son[p].end());
  for (int i = 0; i < son[p].size(); i++) {
    cout << son[p][i] << " ";
  }
  return 0;
}