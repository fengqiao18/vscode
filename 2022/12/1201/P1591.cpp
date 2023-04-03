#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int num1[N], lena;
int helper(int n, int a) {
  lena = 1, num1[1] = 1;
  for (int i = 1; i <= n; i++) {
    int x = 0;
    for (int j = 1; j <= lena; j++) {
      num1[j] = num1[j] * i + x;
      x = num1[j] / 10;
      num1[j] %= 10;
    }
    while (x > 0) {
      num1[++lena] = x % 10;
      x /= 10;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= lena; i++) {
    cnt += num1[i] == a;
  }
  return cnt;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a;
    cin >> n >> a;
    cout << helper(n, a) << endl;
  }
  return 0;
}