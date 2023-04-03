#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt = 0;
  cin >> n;
  while (n != 0) {
    int tmp = n, maxi = -1;
    while (tmp != 0) {
      maxi = max(maxi, tmp % 10);
      tmp /= 10;
    }
    n -= maxi;
    cnt++;
  }
  cout << cnt;
  return 0;
}