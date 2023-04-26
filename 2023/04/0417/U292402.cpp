#include <bits/stdc++.h>
using namespace std;
string s;
int cnt;
bool helper(int x) {
  int n = s.size();
  if (x > n || x < cnt) {
    return 0;
  }
  if (s.size() % 2 == 1) {
    return 1;
  }
  return (cnt - x) % 2 == 0;
}
int main() {
  int q;
  cin >> s >> q;
  for (int i = 0; i < s.size() / 2; i++) {
    cnt += (s[i] != s[s.size() - i - 1]);
    // cout<<s[i]<<" "<<s[s.size() - i - 1]<<'\n';
  }
  // cout<<cnt<<endl;
  while (q--) {
    int x;
    cin >> x;
    cout << (helper(x) ? "YES" : "NO") << endl;
  }
  return 0;
}