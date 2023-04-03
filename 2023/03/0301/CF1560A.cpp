#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N];
void work() {
  int cnt = 0 , num = 1;
  while (cnt <= 1000) {
    if (num % 10 != 3 && num % 3 != 0) {
      a[++cnt] = num;
    }
    num++;
  }
  return;
}
int main() {
  work();  
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    cout << a[k] << endl;
  }
  return 0;
}
