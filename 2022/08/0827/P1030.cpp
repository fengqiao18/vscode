#include <bits/stdc++.h>
using namespace std;
void dfs(string z, string h) {
  if (z.size() == 0) {
    return;
  }
  char rt = h[h.size() - 1];
  int p = z.find(rt);
  cout << rt;
  dfs(z.substr(0, p), h.substr(0, p));
  dfs(z.substr(p + 1), h.substr(p, h.size() - p - 1));
  return;
}
int main() {
  string z, h;
  cin >> z >> h;
  dfs(z, h);
  return 0;
}