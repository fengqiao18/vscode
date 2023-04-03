#include <iostream>
using namespace std;
const int N = 1e5 + 1;
int a[N], p[N], n, x;
void f(int pl, int pr, int ml, int mr) {
  if (pl > pr) {
    return;
  }
  int r = a[pl], x = p[r];
  int sl = x - ml, sr = mr - x;
  f(pl + 1, pl + sl, ml, x - 1);
  f(pr - sr + 1, pr, x + 1, mr);
  cout << r << " ";
  return;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> x;
    p[x] = i;
  }
  f(1, n, 1, n);
  return 0;
}