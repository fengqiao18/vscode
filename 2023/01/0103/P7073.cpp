#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 1e6 + 1;
struct node {
  char c;
  int num, l, r, is_change;
};
node v[kMaxN];
int s[kMaxN];
inline bool num_test(int i) {
  if (v[i].c) {
    if (v[i].c == '!') {
      v[i].num = !num_test(v[i].r);
    } else {
      v[i].num = v[i].c == '&' ? num_test(v[i].l) & num_test(v[i].r) : num_test(v[i].l) | num_test(v[i].r);
    }
  }
  return v[i].num;
}
inline void check(int i) {
  v[i].is_change = 1;
  if (v[i].c == '!') {
    check(v[i].r);
  } else if (v[i].c == '&') {
    if (v[i].num) {
      check(v[i].l), check(v[i].r);
    } else {
      if (v[v[i].l].num) {
        check(v[i].r);
      }
      if (v[v[i].r].num) {
        check(v[i].l);
      }
    }
  } else if (v[i].c == '|') {
    if (v[i].num) {
      if (!v[v[i].l].num) {
        check(v[i].r);
      }
      if (!v[v[i].r].num) {
        check(v[i].l);
      }
    } else {
      check(v[i].l), check(v[i].r);
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  char c;
  int n, t, m = 1e5 + 1, x = 0;
  for (char c; cin >> c; s[++t] = x) {
    if (c == 'x') {
      cin >> x;
    } else if (c >= '0' && c <= '9') {
      cin.putback(c);
      break;
    } else {
      x = m++, v[x].c = c, v[x].r = s[t--];
      if (c == '&' || c == '|') {
        v[x].l = s[t--];
      }
    }
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i].num;
  }
  num_test(s[1]), check(s[1]);
  int q;
  for (cin >> q; q; q--) {
    cin >> x;
    cout << (v[s[1]].num ^ v[x].is_change) << endl;
  }
  return 0;
}