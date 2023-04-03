#include <bits/stdc++.h>
using namespace std;
bool flag1, flag2 , tmp;
int main() {
  int n , ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    if (a == 0) {
      ans++;
      flag1 = flag2 = 0;
    }
    if (a == 1) {
      if (flag1 == 1) {
        ans++;
        flag1 = 0;
      } else {
        flag1 = 1, flag2 = 0;
      }
    }
    if (a == 2) {
      if (flag2 == 1) {
        ans++;
        flag2 = 0;
      } else {
        flag2 = 1, flag1 = 0;
      }
    }
    if (a == 3) {
      if (flag1 == 1) {
        flag1 = 0, flag2 = 1;
        tmp = 1;
      }
      if (flag2 == 1 && tmp == 0) {
        flag2 = 0, flag1 = 1;
      }
      tmp = 0;
    }
  }
  cout << ans;
  return 0;
}