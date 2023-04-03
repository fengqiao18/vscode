#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long a[N];
int n, m, p1, s1, s2;
long long sum1, sum2;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  scanf("%d%d%d%d", &m, &p1, &s1, &s2);
  a[p1] += s1;
  for (int i = 1; i <= m - 1; i++) {
    sum1 += a[i] * (m - i);
  }
  for (int i = m + 1; i <= n; i++) {
    sum2 += a[i] * (i - m);
  }
  int mini = 1e9, pos;
  for (int i = 1; i <= n; i++) {
    long long t1 = sum1;
    long long t2 = sum2;
    if (i < m)
      t1 += (m - i) * s2;
    else if (i > m)
      t2 += (i - m) * s2;
    int tmp = llabs(t1 - t2);
    if (tmp < mini) {
      mini = tmp;
      pos = i;
    }
  }
  printf("%d", pos);
  return 0;
}