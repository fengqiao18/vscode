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
  char opt;
  string s, cur;
  while (cin >> opt >> s) {
    if (opt == '$') {
      return 0;
    } else if (opt == '#') {
      cur = s;
      if (fa[s] == "") {
        fa[s] = s;
      }
    } else if (opt == '+') {
      fa[s] = cur;
    } else {
      cout << s << " " << find(s) << endl;
    }
  }
  return 0;
}