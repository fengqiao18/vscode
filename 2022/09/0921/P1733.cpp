#include<bits/stdc++.h>
using namespace std;

int main() {
  for (int l = 1, r = 1000000000, mid = (l + r) >> 1, res; l <= r; mid = (l + r) >> 1) {
    cout << mid << endl;
    cin >> res;
    if (res == 0) {
      return 0;
    } else if (res == -1) {
      l = mid + 1;
    } else if (res == 1) {
      r = mid - 1;
    } else {
      puts("Input Error!");
    }
  }
  return 0;
}