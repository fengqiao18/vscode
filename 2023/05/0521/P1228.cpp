#include <bits/stdc++.h>
#define ul() dfs(xx + l - 1, yy + l - 1, xx, yy, l)
#define ur() dfs(xx + l - 1, yy + l, xx, yy + l, l)
#define dl() dfs(xx + l, yy + l - 1, xx + l, yy, l)
#define dr() dfs(xx + l, yy + l, xx + l, yy + l, l)
using namespace std;
void dfs(int x, int y, int xx, int yy, int l) {
  if (l == 1) {
    return;
  }
  l >>= 1;
  if (x - xx < l && y - yy < l) {
    cout << xx + l << " " << yy + l << " 1\n";
    dfs(x, y, xx, yy, l);
    ur(), dl(), dr();
  } else if (x - xx < l && y - yy >= l) {
    cout << xx + l << " " << yy + l - 1 << " 2\n";
    dfs(x, y, xx, yy + l, l);
    ul(), dl(), dr();
  } else if (x - xx >= l && y - yy < l) {
    cout << xx + l - 1 << " " << yy + l << " 3\n";
    dfs(x, y, xx + l, yy, l);
    ul(), ur(), dr();
  } else {
    cout << xx + l - 1 << " " << yy + l - 1 << " 4\n";
    dfs(x, y, xx + l, yy + l, l);
    ul(), ur(), dl();
  }
  return;
}
int main() {
  int k, x, y;
  cin >> k >> x >> y;
  dfs(x, y, 1, 1, 1 << k);
  return 0;
}