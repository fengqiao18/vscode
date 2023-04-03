#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N], pos = 0;
void zhuan(int n, int m) {
  pos = 0;
  while (n != 0) {
    a[++pos] = n % m;
    n /= m;
  }
  return;
}
bool hui() {
  int l = 1 , r = pos;
  while(l < r){
    if(a[l] != a[r])
      return 0;
    l++ , r--;
  }
  return 1;
}
void print() {
  for (int i = pos; i >= 1; i--) {
    if (a[i] < 10)
      cout << a[i];
    else{
      char ch = a[i] - 10 + 'A';
      cout<<ch;
    }
  }
  cout << " ";
  return;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= 300; i++) {
    zhuan(i * i, n);
    if (hui()) {
      zhuan(i, n);
      print();
      zhuan(i * i, n);
      print();
      cout << "\n";
    }
  }
}