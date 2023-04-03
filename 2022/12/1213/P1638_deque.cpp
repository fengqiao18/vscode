#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int M = 2e3 + 5;
int a[N], cnt[M];
int sum = 0, mini = 1e9;
int n, m, s, e;
deque<int> dq;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    dq.push_back(i);
    cnt[a[i]]++;
    if (cnt[a[i]] == 1) {
      sum++;
    }
    while (!dq.empty() && cnt[a[dq.front()]] > 1) {
      cnt[a[dq.front()]]--;
      dq.pop_front();
    }
    if (sum == m && i - dq.front() + 1 < mini) {
      mini = i - dq.front() + 1;
      s = dq.front(), e = dq.back();
    }
  }
  cout << s << " " << e;
  return 0;
}