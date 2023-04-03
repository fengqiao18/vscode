#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5;
int a[N];
deque<int> minq, maxq;
int main() {
  int n, k;
  cin >> k >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int st = 1, maxi = -1e9;
  for (int i = 1; i <= n; i++) {
    while (!minq.empty() && a[minq.back()] > a[i]) {
      minq.pop_back();
    }
    while (!maxq.empty() && a[maxq.back()] < a[i]) {
      maxq.pop_back();
    }
    minq.push_back(i);
    maxq.push_back(i);
    while (!minq.empty() && !maxq.empty() && a[maxq.front()] - a[minq.front()] > k) {
      if (maxq.front() < minq.front()) {
        st = maxq.front() + 1;
        maxq.pop_front();
      } else {
        st = minq.front() + 1;
        minq.pop_front();
      }
    }
    maxi = max(maxi, i - st + 1);
  }
  cout << maxi;
  return 0;
}