#include <bits/stdc++.h>
#define ll long long
#define rint register int
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
string dic[35] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "a", "both", "another", "first", "second", "third"};
int num[35] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 1, 2, 1, 1, 2, 3};
int ans[10], cnt;
string t;
int main() {
  for (int i = 1; i <= 6; i++) {
    cin >> t;
    for (int j = 1; j <= 26; j++) {
      if (dic[j] == t) {
        ans[++cnt] = num[j] * num[j] % 100;
        break;
      }
    }
  }
  cin >> t;
  sort(ans + 1, ans + cnt + 1);
  bool flag = 0;
  for (int i = 1; i <= cnt; i++) {
    if (!flag && ans[i] == 0)
      continue;
    if (ans[i] < 10 && flag)
      cout << 0;
    cout << ans[i];
    flag = 1;
  }
  if (!flag) {
    cout << 0;
  }
  return 0;
}