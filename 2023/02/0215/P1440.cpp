#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
deque<int> dq;
int a[N];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cout << 0 << endl;
  for (int i = 1; i <= n - 1; i++) {
    while (!dq.empty() && a[i] < a[dq.back()]) {
      dq.pop_back();
    }
    dq.push_back(i);
    while (!dq.empty() && i - dq.front() + 1 > k) {
      dq.pop_front();
    }
    cout << a[dq.front()] << "\n";
  }
  return 0;
}