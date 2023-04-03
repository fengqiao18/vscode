#include <iostream>
using namespace std;
const int kMaxN = 20;
struct L {
  int p, n;
} l[kMaxN];
bool a[kMaxN * 2], b[kMaxN * 2];
int n, ans;
inline void fd(int i) {
  if (i > n) {
    ans++;
    return;
  }
  for (int j = l[0].n; j; j = l[j].n) {
    if (!a[i + j] && !b[i - j + n]) {
      a[i + j] = b[i - j + n] = 1;
      l[l[j].p].n = l[j].n, l[l[j].n].p = l[j].p;
      fd(i + 1);
      l[l[j].p].n = l[l[j].n].p = j;
      a[i + j] = b[i - j + n] = 0;
    }
  }
  return;
}
int main() {
  cin >> n;
  for (int i = 0; i <= n; i++) {
    l[i].n = (i + 1) % (n + 1), l[i].p = (i + n) % (n + 1);
  }
  fd(1);
  cout << ans;
  return 0;
}