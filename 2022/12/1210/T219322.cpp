#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N], tail;
int main() {
  int q;
  for (cin >> q; q; q--) {
    char c;
    cin >> c;
    if (c == 'I') {
      cin >> a[++tail];
    } else if (c == 'D') {
      tail--;
    } else {
      int d;
      cin >> d;
      cout << a[tail - d] << " ";
    }
  }
  return 0;
}