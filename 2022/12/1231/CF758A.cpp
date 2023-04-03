#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, maxi = -1e9;
  long long sum = 0;
  cin >> n;
  for (int x = 1; x <= n; x++) {
    int a;
    cin >> a;
    maxi = max(maxi, a);
    sum += a;
  }
  cout << n * maxi - sum;
  return 0;
}