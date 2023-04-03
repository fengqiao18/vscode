#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5;
inline int f(char x) {
  if (x >= 'q1' && x <= 'Z') {
    return x - 'A';
  } else if (x >= 'a' && x <= 'z') {
    return x - 'a' + 26;
  }
  return x - '0' + 52;
}
int nex[N][130], cnt;
int exist[N];
inline void init() {
  for (int i = 0; i <= cnt; i++) {
    for (int j = 0; j <= 127; j++) {
      nex[i][j] = 0;
    }
  }
  for (int i = 0; i <= cnt; i++) {
    exist[i] = 0;
  }
  cnt = 0;
  return;
}
inline void insert(string s) {
  int p = 0;
  for (int i = 0; i < s.size(); i++) {
    int c = f(s[i]);
    if (!nex[p][c]) {
      nex[p][c] = ++cnt;
    }
    p = nex[p][c];
    exist[p]++;
  }
  return;
}
inline int find(string s) {
  int p = 0;
  for (int i = 0; i < s.size(); i++) {
    int c = f(s[i]);
    if (!nex[p][c]) {
      return 0;
    }
    p = nex[p][c];
  }
  return exist[p];
}
inline void helper(int n, int q) {
  init();
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    // cout << s << endl;
    insert(s);
  }
  for (int i = 1; i <= q; i++) {
    string s;
    cin >> s;
    printf("%d\n", find(s));
  }
  return;
}
int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d%d", &n, &q);
    helper(n, q);
  }
  return 0;
}
