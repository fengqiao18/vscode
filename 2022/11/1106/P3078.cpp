#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], diff[N];
int main() {
  int n;
  long long sum = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    diff[i] = a[i] - a[i - 1];
    if (diff[i] > 0) {
      sum += diff[i];
    }
  }
  cout << sum;
  return 0;
}