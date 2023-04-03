#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int cnt0[N], cnt1[N];
int last0[N], last1[N];
void helper() {
  memset(cnt0, 0, sizeof(cnt0));
  memset(cnt1, 0, sizeof(cnt1));
  memset(last0, 0, sizeof(last0));
  memset(last1, 0, sizeof(last1));
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    cnt0[i + 1] = cnt0[i] + (s[i] == '0');
    cnt1[i + 1] = cnt1[i] + (s[i] == '1');
  }
  for (int i = s.size() - 1; i >= 0; i--) {
    last0[i + 1] = last0[i + 2] + (s[i] == '0');
    last1[i + 1] = last1[i + 2] + (s[i] == '1');
  }
  int ans = 1e9;
  for (int i = 1; i <= s.size(); i++) {
    int tmp1 = cnt0[i] + last1[i + 1];
    int tmp2 = cnt1[i] + last0[i + 1];
    ans = min(ans, min(tmp1, tmp2));
  }
  cout << ans << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    helper();
  }
  return 0;
}