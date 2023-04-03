#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
struct small_node {
  int tree[N], len;
  void push(int &x) {
    tree[++len] = x;
    for (int i = len; i > 1 && tree[i] < tree[i / 2]; i >>= 1) {
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
      if (j < len && tree[j] > tree[j + 1]) {
        ++j;
      }
      if (tree[i] < tree[j]) {
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
small_node q;
int a[N];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (a[x]) {
      continue;
    }
    a[x]++;
    q.push(x);
  }
  while (!q.empty()) {
    k--;
    if (k == 0) {
      cout << q.top();
      return 0;
    }
    q.pop();
  }
  cout << "NO RESULT";
  return 0;
}