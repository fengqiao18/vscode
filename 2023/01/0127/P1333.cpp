#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int M = 2e6 + 5;
int fa[N] , deg[N] , G[55];
int n, tot;
inline int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); };
inline void unnion(int x, int y) { x = find(x), y = find(y), fa[x] = y; }
struct Trie {
  int son[26], num;
} trie[M];
int insert(string str) {
  int k = 0;
  for (int i = 0; i < str.size(); i++) {
    int tmp = str[i] - 'a';
    if (trie[k].son[tmp] == 0) {
      trie[k].son[tmp] = ++tot;
    }
    k = trie[k].son[tmp];
  }
  if (trie[k].num == 0) {
    trie[k].num = ++n;
  }
  return trie[k].num;
}
int main() {
  for (int i = 1; i <= 5e5; i++) {
    fa[i] = i;
  }
  string s, t;
  while (cin >> s >> t) {
    int x = insert(s), y = insert(t);
    unnion(x, y);
    deg[x]++, deg[y]++;
  }
  int cnt = deg[1] % 2 == 1;
  for (int i = 2; i <= n; i++) {
    if (find(i) != find(i - 1)) {
      cnt += 10;
    }
    if (deg[i] % 2 == 1) {
      cnt++;
    }
  }
  if (cnt > 2) {
    cout << "Impossible";
  } else {
    cout << "Possible";
  }
  return 0;
}
