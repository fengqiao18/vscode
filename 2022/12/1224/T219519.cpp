#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 2e5 + 1;
struct V {
  char c;
  int a, l, r;
} v[kMaxN];
int s[kMaxN], n, t;
void f(int i) {
  if (v[i].l) {
    cout << '(';
    f(v[i].l);
    cout << ' ' << v[i].c << ' ';
    f(v[i].r);
    cout << ')';
  } else {
    cout << v[i].a;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i].c;
    if (v[i].c >= '0' && v[i].c <= '9') {
      cin.putback(v[i].c);
      cin >> v[i].a;
    } else {
      v[i].r = s[t--], v[i].l = s[t--];
    }
    s[++t] = i;
  }
  f(n);
  return 0;
}