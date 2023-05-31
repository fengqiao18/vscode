#include <bits/stdc++.h>
#define int long long
using namespace std;
map<int, int> mp;
string helper() {
  int n;
  cin >> n;
  for (int i = 1; i <= 1e4; i++) {
    if (mp[n - i * i * i]) {
      return "YES";
    }
  }
  return "NO";
}
signed main() {
  int t;
  cin >> t;
  for (int i = 1; i <= 1e4; i++) {
    mp[i * i * i] = 1;
  }
  while (t--) {
    cout << helper() << endl;
  }
  return 0;
}