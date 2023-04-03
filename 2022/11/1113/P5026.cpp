#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
const int K = 1e6;
int diff[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int v, x;
    cin >> v >> x;
    diff[x - 3 * v + 1 + K]++;
    diff[x - 2 * v + 1 + K] -= 2;
    diff[x + 1 + K] += 2;
    diff[x + 2 * v + 1 + K] -= 2;
    diff[x + 3 * v + 1 + K]++;
  }
  int ans = 0, now = 0;
  for (int i = 0; i <= K; i++) {
    now += diff[i];
    ans += now;
  }
  for (int i = K + 1; i <= m + K; i++) {
    now += diff[i];
    ans += now;
    cout << ans << " ";
  }
  return 0;
}