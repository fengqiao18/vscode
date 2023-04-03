#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (a > b) {
    swap(a, b);
  }
  if (b == a * 2 || b == a * 2 + 1) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}