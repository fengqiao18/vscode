#include <bits/stdc++.h>
#define rint register int
using namespace std;
const int N = 1e5 + 5;
int a[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  char c;
  int n, m;
  int x, y;
  cin >> n >> m;
  for (rint i = 1; i <= m; ++i) {
    cin >> c;
    if (c == 'C') {
      cin >> x >> y;
      for (rint j = x; j <= y; ++j) {
        a[j] = a[j] + j - x + 1;
      }
    } else {
      cin >> x;
      cout << a[x] << '\n';
    }
  }
  return 0;
}