#include <bits/stdc++.h>
#define rint register int
using namespace std;
const int N = 1e6 + 5;
int a[N];
deque<int> dq;
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (rint i = 1; i <= n; i++) {
    cin >> a[i];
    while (!dq.empty() && a[i] >= a[dq.back()]) {
      dq.pop_back();
    }
    dq.push_back(i);
    while (!dq.empty() && i - dq.front() + 1 > k) {
      dq.pop_front();
    }
    if (i >= k) {
      cout << a[dq.front()] << '\n';
    }
  }
  return 0;
}