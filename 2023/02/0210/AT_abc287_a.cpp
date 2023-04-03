#include <bits/stdc++.h>
using namespace std;
int cnt[2];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    cnt[s == "Against"]++;
  }
  // cout << cnt[1] << " " << cnt[0] << endl;
  cout << (cnt[1] > cnt[0] ? "No" : "Yes");
  return 0;
}