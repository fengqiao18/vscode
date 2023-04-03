#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char a[N];
int l1, l2;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == '1' && l1 == 0) {
      l1 = i;
    } else if (a[i] == '1' && l2 == 0) {
      l2 = i;
    }
  }
  for (int i = l2 + 1; i <= n; i++) {
    if (a[i] == '1' && i - l2 == l2 - l1) {
      l1 = l2, l2 = i;
    } else if (a[i] == '1') {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}