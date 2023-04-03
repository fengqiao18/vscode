#include <bits/stdc++.h>
using namespace std;
const int N = 130;
char a, b, c, root;
vector<char> tre[N];
int n;
void dfs(char root) {
  if (root == '*') {
    return;
  }
  cout << root;
  dfs(tre[root][0]);
  dfs(tre[root][1]);
  return;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b >> c;
    if (i == 1) {
      root = a;
    }
    tre[a].push_back(b);
    tre[a].push_back(c);
  }
  dfs(root);
  return 0;
}