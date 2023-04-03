#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5;
int a[N], ans[N];
stack<int> stk;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    while (!stk.empty() && a[i] > a[stk.top()]) {
      ans[stk.top()] = i;
      stk.pop();
    }
    stk.push(i);
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}