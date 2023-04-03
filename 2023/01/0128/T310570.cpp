#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N = 1005;
int f[N];
unordered_map<ull, int> mp;
signed main() {
  int n , q;
  string s;
  cin >> n >> q >> s;
  s = " " + s;
  for (int i = 1; i <= n; i++) {
    ull tmp = 0;
    for (int j = i; j <= n; j++) {
      tmp = tmp * 19260817ll + s[j];
      mp[tmp]++;
    }
  }
  for (auto k = mp.begin(); k != mp.end(); k++) {
    f[k->second]++;
  }
  for (int i = 1; i <= n; i++) {
    f[i] += f[i - 1];
  }
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    cout << f[r] - f[l - 1] << endl;
  }
  return 0;
}
