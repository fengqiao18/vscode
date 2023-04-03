#include <bits/stdc++.h>
using namespace std;
int a[30005], w, n;
int cnt = 0;
int main() {
  cin >> w >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + 1 + n);
  int l = 1, r = n;
  while (l <= r) {
    cnt++;
    if (a[l] + a[r] <= w)
      l++;
    r--;
  }
  cout << cnt;
  return 0;
}