#include <iostream>
using namespace std;
const int kMaxN = 5e3 + 1, kMaxQ = 5e5 + 1;
struct E {
  int v, n;
} e[kMaxQ];
struct L {
  int h, t;
} l[kMaxN];
int n, q, x, y;
int main() {
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> x >> e[i].v;
    if (!l[x].h) {
      l[x].h = l[x].t = i;
    } else {
      l[x].t = e[l[x].t].n = i;
    }
  }
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    if (!l[x].h) {
      l[x].h = l[y].h;
    } else if (l[y].h) {
      e[l[x].t].n = l[y].h;
    }
    l[x].t = l[y].t;
    l[y].h = 0;
  }
  for (x = 1; !l[x].h; x++) {
  }
  for (int i = l[x].h; i; i = e[i].n) {
    cout << e[i].v << " ";
  }
  return 0;
}