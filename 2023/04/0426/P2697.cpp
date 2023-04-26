#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int sumr[N], sumg[N];
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    sumr[i] = sumr[i - 1] + (s[i] == 'R');
    sumg[i] = sumg[i - 1] + (s[i] == 'G');
  }
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j <= i; j++) {
      if (sumr[i] - sumr[j - 1] == sumg[i] - sumg[j - 1]) {
        ans = max(ans, i - j + 1);
      }
    }
  }
  cout << ans;
  return 0;
}