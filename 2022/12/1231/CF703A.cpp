#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
      cnt++;
    } else if (a < b) {
      cnt--;
    } else {
      cnt = cnt;
    }
  }
  if (cnt > 0) {
    cout << "Mishka";
  } else if (cnt < 0) {
    cout << "Chris";
  } else {
    cout << "Friendship is magic!^^";
  }
  return 0;
}
