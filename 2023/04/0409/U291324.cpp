#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int vis = s.size();
  for (char i = 'a'; i <= 'z'; i++) {
    for (int j = s.size() - 1; j >= 0; j--) {
      if (s[j] == i) {
        // cout<<i<<" "<<j<<"\n";
        vis = j;
        break;
      }
    }
    if (vis != s.size()) {
      break;
    }
  }
  // cout<<vis<<" ";
  cout << s[vis];
  // cout<<endl;
  for (int i = 0; i < s.size(); i++) {
    if (i != vis) {
      cout << s[i];
    }
  }
  return 0;
}
