#include <iostream>
using namespace std;
const int N = 5e3 + 5, M = 5e5 + 5;
struct node {
  int v, p;
} e[M];
int t[N];
int n, q, x;
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> x >> e[i].v;
    e[i].p = t[x], t[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = t[i]; j; j = e[j].p) {
      cout << e[j].v << " ";
    }
    cout << '\n';
  }
  return 0;
}