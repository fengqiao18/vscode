#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], vis[N];
long long sum[N];
stack<int> stk;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  long long maxi = -1e18;
  for (int i = 1; i <= n; i++) {
    while (!stk.empty() && a[i] < a[stk.top()]) {
      maxi = max(maxi, (sum[i - 1] - sum[vis[stk.top()]]) * a[stk.top()]);
      stk.pop();
    }
    if (!stk.empty()) {
      vis[i] = stk.top();
    } else {
      vis[i] = 0;
    }
    stk.push(i);
  }
  cout << maxi;
  return 0;
}