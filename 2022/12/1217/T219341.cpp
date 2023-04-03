#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N];
int hd = 1, tl;
int main() {
  // freopen("1.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    // cout<<"sdbheth";
    if (c == 'I') {
      int p;
      cin >> p;
      // cout<<p<<endl;
      a[++tl] = p;
    } else if (c == 'D') {
      hd++;
    } else {
      int t;
      cin >> t;
      cout << a[hd + t] << " ";
    }
  }
  return 0;
}