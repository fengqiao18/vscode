
#include <iostream>

using namespace std;

const int kL = 1e6, kM = 1e9 + 7;

int e[kL];
int n, q, h = 1, t, d;
long long a, x, y;
char o;

int main() {
  cin >> q;
  while (q--) {
    cin >> o;
    if (o == 'I') {
      cin >> n >> x >> y;
      a = 1;
      for (int i = 1; i <= n; i++) {
        a = (a * x + y) % kM;
        t = (t + 1) % kL;
        e[t] = a;
      }
    } else if (o == 'D') {
      cin >> n;
      h = (h + n) % kL;
    } else {
      cin >> d;
      cout << e[(h + d) % kL] << " ";
    }
  }
  return 0;
}