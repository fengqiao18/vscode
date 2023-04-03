#include <bits/stdc++.h>
using namespace std;
void dfs(string x, string z) {
  if (x == "") {
    return;
  }
  char rt = x[0];
  int p = z.find(rt);
  dfs(x.substr(1, p), z.substr(0, p));
  dfs(x.substr(p + 1), z.substr(p + 1));
  cout << rt;
  return;
}
int main() {
  string x, z;
  cin >> x >> z;
  dfs(x, z);
  return 0;
}