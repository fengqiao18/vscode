#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 55;
int a[N];
inline bool helper(int n) {
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i] == a[j] && s[i - 1] != s[j - 1]) {
        return 1;
      }
    }
  }
  return 0;
}
signed main() {
  // freopen("1.in", "r", stdin);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (helper(n) ? "NO" : "YES") << endl;
  }
  return 0;
}