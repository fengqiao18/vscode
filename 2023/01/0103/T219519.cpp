#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node {
  char c;
  int a, l, r;
};
node v[N];
int s[N];
inline void helper(int i) {
  if (v[i].l) {
    cout << "(";
    helper(v[i].l);
    cout << " " << v[i].c << " ";
    helper(v[i].r);
    cout << ")";
  } else {
    cout << v[i].a;
  }
  return;
}
int main() {
  int n, cnt = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i].c;
    if (v[i].c >= '0' && v[i].c <= '9') {
      cin.putback(v[i].c);
      cin >> v[i].a;
    } else {
      v[i].r = s[cnt--], v[i].l = s[cnt--];
    }
    s[++cnt] = i;
  }
  helper(n);
  return 0;
}