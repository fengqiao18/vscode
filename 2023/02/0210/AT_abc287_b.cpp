#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
string s[N];
bool vis[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string t;
    cin >> t;
    for (int j = t.size() - 3; j <= t.size() - 1; j++) {
      s[i] += t[j];
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    string t;
    cin >> t;
    for (int j = 1; j <= n; j++) {
      if (s[j] == t && !vis[j]) {
        ans++;
        // cout<<j<<endl;
        vis[j] = 1;
      }
    }
  }
  cout << ans;
  return 0;
}