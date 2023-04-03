#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int h[N], v[N];
int ans[N];
stack<int> stk;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i] >> v[i];
  }
  for (int i = 1; i <= n; i++) {
    while (!stk.empty() && h[stk.top()] < h[i]) {
      ans[i] += v[stk.top()];
      stk.pop();
    }
    if (!stk.empty()) {
      ans[stk.top()] += v[i];
    }
    stk.push(i);
  }
  int maxi = -1e9;
  for (int i = 1; i <= n; i++) {
    maxi = max(maxi, ans[i]);
  }
  cout << maxi;
  return 0;
}