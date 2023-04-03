#include <bits/stdc++.h>
using namespace std;
string str = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes";
int main() {
  // freopen("1.out", "w", stdout);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (str.find(s) >= str.size()) {
      cout << "NO";
    } else {
      cout << "YES";
    }
    cout << endl;
  }
  return 0;
}
