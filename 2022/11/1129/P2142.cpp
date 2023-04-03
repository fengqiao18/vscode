#include <bits/stdc++.h>
using namespace std;
const int N = 10100;
int num1[N], num2[N], num3[N];
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  if (s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2)) {
    swap(s1, s2);
    cout << "-";
  }
  int n = s1.size(), m = s2.size();
  for (int i = 0; i < n; i++) {
    num1[n - i] = s1[i] - '0';
  }
  for (int i = 0; i < m; i++) {
    num2[m - i] = s2[i] - '0';
  }
  int len = max(n, m);
  for (int i = 1; i <= len; i++) {
    if (num2[i] > num1[i]) {
      num1[i] += 10;
      num1[i + 1]--;
    }
    num3[i] = num1[i] - num2[i];
  }
  while (num3[len] == 0 && len > 0) {
    len--;
  }
  if(len == 0){
    cout<<0;
  }
  for (int i = len; i >= 1; i--) {
    cout << num3[i];
  }
  return 0;
}