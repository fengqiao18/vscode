#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, sum = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    sum += (x > k ? 2 : 1);
  }
  cout << sum;
  return 0;
}