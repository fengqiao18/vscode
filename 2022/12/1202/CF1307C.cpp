#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const int M = 30;
ll f[N][M], ans[M][M];
string s;
int main() {
  cin >> s;
  int len = s.size();
  s = '*' + s;
  for (int i = len; i >= 1; i--) {
    f[i][s[i] - 'a']++;
    for (int j = 0; j < 26; j++) {
      f[i][j] += f[i + 1][j];
    }
  }
  for (int i = 1; i < len; i++) {
    for (int j = 0; j < 26; j++) {
      ans[s[i] - 'a'][j] += f[i + 1][j];
    }
  }
  long long res = -1;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      res = max(res, ans[i][j]);
    }
    res = max(res, (long long)f[1][i]);
  }
  cout << res;
  return 0;
}