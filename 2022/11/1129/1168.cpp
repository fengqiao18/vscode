#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int num1[N], num2[N], num3[N];
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.size(), m = s2.size();
  for (int i = 0; i < n; i++) {
    num1[n - i] = s1[i] - '0';
  }
  for (int i = 0; i < m; i++) {
    num2[m - i] = s2[i] - '0';
  }
  int len = max(n, m);
  int x = 0;
  for (int i = 1; i <= len; i++) {
    int tmp = num1[i] + num2[i] + x;
    num3[i] = tmp % 10;
    x = tmp / 10;
  }
  if (x > 0) {
    num3[++len] = x;
  }
  bool flag = 0;
  for (int i = len; i >= 1; i--) {
    if(num3[i] == 0 && !flag){
      continue;
    }
    flag = 1;
    cout << num3[i];
  }
  return 0;
}