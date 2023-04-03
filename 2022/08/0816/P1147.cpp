#include <bits/stdc++.h>
using namespace std;
int ans;
int main() {
  int m;
  cin >> m;
  int lt = 1, rt = 0;
  while (rt < m) {
    if (ans == m)
      cout << lt << " " << rt << endl;
    if (ans < m) {
      rt++;
      ans += rt;
    } else {
      ans -= lt;
      lt++;
    }
  }
  return 0;
}