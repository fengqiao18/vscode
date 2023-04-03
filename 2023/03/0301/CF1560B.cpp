#include <bits/stdc++.h>
using namespace std;
void helper() {
  int a, b, c, d, all;
  cin >> a >> b >> c;
  all = abs(a - b) * 2;
  if (a > all || b > all) {
    cout << -1;
    return;
  }
  int tmp = all / 2;
  if (c <= tmp) {
    d = tmp + c;
    // cout << "ddd";
  } else {
    d = c - tmp;
  }
  if (d > all || c > all) {
    cout << -1;
    return;
  }
  cout << d;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    helper();
    cout << endl;
  }
  return 0;
}