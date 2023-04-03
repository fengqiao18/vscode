#include <bits/stdc++.h>
using namespace std;
string str;
bool val, ed, st;
int ans1, ans2, off;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if (off) {
      if (str[i] == '(') {
        int x = 1;
        while (x) {
          i++;
          if (str[i] == '(') x++;
          if (str[i] == ')') x--;
        }
      } else if (off == 1 && str[i] == '|') {
        off = 0;
      } else if (str[i] == ')') {
        off = 0;
      } else if (off == 1 && str[i] == '&') {
        ans1++;
      } else if (off == 2 && str[i] == '|') {
        ans2++;
      }
    } else {
      if (str[i] == '1') val = 1;
      if (str[i] == '0') val = 0;
      if (str[i] == '&' && val == 0) {
        off = 1;
        ans1++;
      }
      if (str[i] == '|' && val == 1) {
        off = 2;
        ans2++;
      }
    }
  }
  cout << val << endl
       << ans1 << ' ' << ans2 << endl;
  return 0;
}