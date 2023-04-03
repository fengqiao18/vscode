#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
int a[N];
long long b[N];
inline int helper(int n) {
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n; i >= 1; i--) {
    if (i + a[i] > n) {
      b[i] = a[i];
    } else {
      b[i] = a[i] + b[i + a[i]];
    }
  }
  long long maxi = -1e9;
  for (int i = 1; i <= n; i++) {
    maxi = max(maxi, b[i]);
  }
  return maxi;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << helper(n) << endl;
  }
  return 0;
}