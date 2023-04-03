#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node {
  bool b;
  int l, r;
};
node v[N];
void T(int x, int t) {
  if (!x) {
    return;
  }
  if (t == 0) {
    cout << x << " ";
  }
  T(v[x].l, t);
  if (t == 1) {
    cout << x << " ";
  }
  T(v[x].r, t);
  if (t == 2) {
    cout << x << " ";
  }
  return;
}
int main() {
  int n, r;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i].l >> v[i].r;
    v[v[i].l].b = v[v[i].r].b = 1;
  }
  for (r = 1; v[r].b; r++) {
  }
  T(r, 0);
  cout << '\n';
  T(r, 1);
  cout << '\n';
  T(r, 2);
  return 0;
}