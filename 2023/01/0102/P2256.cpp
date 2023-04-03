#include <bits/stdc++.h>
using namespace std;
map<string, string> fa;
inline string find(string x) { return fa[x] == x ? x : fa[x] = find(fa[x]); };
inline void unionn(string x, string y) {
  x = find(x), y = find(y);
  if (x != y) {
    fa[x] = y;
  }
  return;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    fa[s] = s;
  }
  for (int i = 1; i <= m; i++) {
    string x, y;
    cin >> x >> y;
    unionn(x, y);
  }
  int k;
  cin >> k;
  while (k--) {
    string x, y;
    cin >> x >> y;
    if (find(x) == find(y)) {
      cout << "Yes.\n";
    } else {
      cout << "No.\n";
    }
  }
  return 0;
}