#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, m, q;
  long long ans1 = 0, ans2 = 0;
  cin >> n >> p;
  int a[n];
  for (int i = 0; i <= n - 1; i++) {
    cin >> a[i];
    ans1 = ans1 * p + a[i];
  }
  cin >> m >> q;
  int b[n];
  for (int i = 0; i <= m - 1; i++) {
    cin >> b[i];
    ans2 = ans2 * q + b[i];
  }
  if (ans1 == ans2)
    cout << "=";
  else if (ans1 > ans2)
    cout << ">";
  else
    cout << "<";
  return 0;
}