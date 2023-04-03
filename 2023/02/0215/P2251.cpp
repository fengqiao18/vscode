#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
deque<int> dq;
int a[N];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    while (!dq.empty() && a[i] < a[dq.back()]) {
      dq.pop_back();
    }
    dq.push_back(i);
    while (!dq.empty() && i - dq.front() + 1 > k) {
      dq.pop_front();
    }
    if (i >= k) {
      cout << a[dq.front()] << endl;
    }
  }
  return 0;
}