#include <bits/stdc++.h>
using namespace std;
const int N = 4005;
int num1[N], num2[N], ans[N];
int main() {
  string a, b;
  cin >> a >> b;
  int lena = a.size(), lenb = b.size();
  for (int i = 0; i < lena; i++) {
    num1[lena - i] = a[i] - '0';
  }
  for (int i = 0; i < lenb; i++) {
    num2[lenb - i] = b[i] - '0';
  }
  for (int i = 1; i <= lenb; i++) {
    int x = 0;
    for (int j = 1; j <= lena; j++) {
      ans[i + j - 1] += num1[j] * num2[i] + x;
      x = ans[i + j - 1] / 10;
      ans[i + j - 1] %= 10;
    }
    ans[i + lena] = x;
  }
  int lenc = lena + lenb;
  while (lenc > 1 && ans[lenc] == 0) {
    lenc--;
  }
  for (int i = lenc; i >= 1; i--) {
    cout << ans[i];
  }
  return 0;
}