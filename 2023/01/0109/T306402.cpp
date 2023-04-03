#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  if (s[0] == 'A' && s[n - 1] == 'B') {
    cout << "No";
  } else {
    cout << "Yes";
  }
  return 0;
}