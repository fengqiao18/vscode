#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = n; i >= 1; i--) {
    if (a[i] + cnt <= k) {
      cnt += a[i];
    } else {
      m--, cnt = 0;
      if (m == 0) {
        cout << i;
        return 0;
      }
      i++;
    }
    // cout<<cnt<<endl;
  }
  cout << 0;
  return 0;
}