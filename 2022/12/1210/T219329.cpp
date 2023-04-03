#include <bits/stdc++.h>
using namespace std;
stack<int> stk;
string s;
const int N = 1e5 + 5;
int a[N];
int main() {
  int n;
  cin >> n >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      stk.push(i);
    } else {
      int cur = stk.top();
      stk.pop();
      a[cur] = i, a[i] = cur;
    }
  }
  for (int i = 0; i < s.size(); i++) {
    cout << a[i] + 1 << " ";
  }
  return 0;
}