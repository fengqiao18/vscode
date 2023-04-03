#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  long long odd = ceil(a / 2.0);
  if (b > odd) {
    cout << (b - odd) * 2 << endl;
  } else {
    cout << b * 2 - 1 << endl;
  }
  return 0;
}
