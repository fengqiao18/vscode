#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
struct big_node {
  int tree[N], len;
  void push(int &x) {
    tree[++len] = x;
    for (int i = len; i > 1 && tree[i] > tree[i / 2]; i >>= 1) {
      swap(tree[i], tree[i / 2]);
    }
  }
  int top() {
    return tree[1];
  }
  void pop() {
    tree[1] = tree[len--];
    for (int i = 1; (i << 1) <= len;) {
      int j = i << 1;
      if (j < len && tree[j] < tree[j + 1]) {
        ++j;
      }
      if (tree[i] > tree[j]) {
        break;
      } else {
        swap(tree[i], tree[j]);
      }
      i = j;
    }
    return;
  }
  int size() {
    return len;
  }
  bool empty() {
    return len == 0;
  }
};
big_node q;
int ans[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    for (int j = 1; j <= m; j++) {
      int tmp = a * j * j + b * j + c;
      if (i == 1) {
        q.push(tmp);
      } else {
        if (tmp < q.top()) {
          q.push(tmp);
          q.pop();
        } else {
          break;
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    ans[i] = q.top();
    q.pop();
  }
  for (int i = m; i >= 1; i--) {
    cout << ans[i] << " ";
  }
  return 0;
}
