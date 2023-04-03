#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int sum_yue(int n) {
  int sum = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      sum += i;
      sum += n / i;
    }
  }
  int t = sqrt(n);
  if (t * t == n) {
    sum -= t;
  }
  return sum - n;
}
int a[N];
void yu() {
  for (int i = 1; i <= 1e5; i++) {
    a[i] = sum_yue(i);
  }
  return;
}
int main() {
  int n;
  cin >> n;
  yu();
  for (int i = n;; i++) {
    int fri = a[i];
    if (a[fri] == i && fri != i) {
      cout << i << " " << fri;
      return 0;
    }
  }
  return 0;
}