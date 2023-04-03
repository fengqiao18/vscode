#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, lena;
int num1[N];
void helper() {
  lena = 1, num1[1] = 1;
  for (int i = 1; i <= n; i++) {
    int x = 0;
    for (int j = 1; j <= lena; j++) {
      num1[j] = num1[j] * 2 + x;
      x = num1[j] / 10;
      num1[j] %= 10;
    }
    while (x > 0) {
      num1[++lena] = x % 10;
      x /= 10;
    }
  }
  for (int i = lena; i >= 2; i--) {
    cout << num1[i];
  }
  cout << num1[1] - 1;
  return;
}
int main() {
  cin >> n;
  helper();
  return 0;
}