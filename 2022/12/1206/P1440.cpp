#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, m, a[N], q[N], h, t;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  printf("0\n");
  h = 1;
  t = 1;
  q[1] = 1;
  for (int i = 2; i <= n; i++) {
    while (q[h] < i - m) h++;
    printf("%d\n", a[q[h]]);
    while (a[i] < a[q[t]] && t >= h) t--;
    q[++t] = i;
  }
  return 0;
}