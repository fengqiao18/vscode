#include <bits/stdc++.h>
#define r register
using namespace std;
const int N = 3e6 + 5;
struct trie {
  int nex[N][26], cnt;
  bool exist[N];
  int dm[N];
  inline void insert(string s) {
    int p = 0;
    for (r int i = 0; i < s.size(); i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) {
        nex[p][c] = ++cnt;
      }
      p = nex[p][c];
    }
    exist[p] = 1;
  }
  inline int find(string s) {
    int l = s.size();
    int p = 0;
    for (r int i = 0; i < s.size(); i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) {
        return 0;
      }
      p = nex[p][c];
    }
    if (exist[p]) {
      if (dm[p] == 0) {
        dm[p] = 1;
      } else {
        dm[p] = 2;
      }
      return dm[p];
    } else {
      return 0;
    }
  }
};
trie tree;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  string s;
  for (r int i = 1; i <= n; i++) {
    cin >> s;
    tree.insert(s);
  }
  int q;
  cin >> q;
  for (r int i = 1; i <= q; i++) {
    string s;
    cin >> s;
    int tmp = tree.find(s);
    if (tmp == 1) {
      cout << "OK";
    } else if (tmp == 2) {
      cout << "REPEAT";
    } else {
      cout << "WRONG";
    }
    cout << endl;
  }
  return 0;
}
