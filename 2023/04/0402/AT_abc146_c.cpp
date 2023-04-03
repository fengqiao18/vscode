#include <bits/stdc++.h>
#define int long long
using namespace std;
int a, b, c, ans;
bool check(int mid) {
  int t = mid , x = 0;
  while(t){
    t /= 10;
    x++;
  }
  return (a * mid + b * x) <= c;
}
signed main() {
  cin >> a >> b >> c;
  int lt = 0, rt = 1e9;
  while (lt < rt) {
    int mid = (lt + rt + 1) / 2;
    if (check(mid)) {
      lt = mid;
    } else {
      rt = mid - 1;
    }
  }
  cout << rt;
  return 0;
}
