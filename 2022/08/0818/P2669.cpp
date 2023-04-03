#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int a[N];
void yu() {
  int cnt = 0, duan = 1;
  for (int i = 1; i <= 10000; i++) {
    a[i] = duan;
    cnt++;
    if (cnt == duan) {
      duan++;
      cnt = 0;
    }
  }
}
int main() {
  int n, sum = 0;
  cin >> n;
  yu();
  for (int i = 1; i <= n; i++)
    sum += a[i];
  cout << sum;
  return 0;
}