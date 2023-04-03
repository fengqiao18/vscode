#include <bits/stdc++.h>
using namespace std;
void dfs(string z, string q) {
  if (z.size() == 0) {
    return;
  }
  char rt = q[0];
  int p = z.find(rt);
  dfs(z.substr(0, p), q.substr(1, p + 1));
  dfs(z.substr(p + 1), q.substr(p + 1));
  cout << rt;
  return;
}
int main() {
  string z, q;
  cin >> z >> q;
  dfs(z, q);
  return 0;
}