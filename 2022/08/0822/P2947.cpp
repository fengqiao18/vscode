#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], ans[N], cnt;
struct node {
  int num, id;
};
stack<node> stk;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ans[++cnt] = 0;
  stk.push((node){a[n], n});
  for (int i = n - 1; i >= 1; i--) {
    while (!stk.empty() && stk.top().num <= a[i]) {
      stk.pop();
    }
    if (stk.empty()) {
      ans[++cnt] = 0;
    } else {
      ans[++cnt] = stk.top().id;
    }
    stk.push((node){a[i], i});
  }
  for (int i = cnt; i >= 1; i--) {
    cout << ans[i] << endl;
  }
  return 0;
}