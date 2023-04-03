#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
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
big_node q1;
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
small_node q2;
int a[N];
int main() {
  int n, m, fg = 1, q;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> q;
    for (int j = fg; j <= q; j++) {
      q1.push(a[j]);
      if (q1.size() == i) {
        int tmp = q1.top();
        q2.push(tmp);
        q1.pop();
      }
    }
    fg = q + 1;
    cout << q2.top() << endl;
    int tmp = q2.top();
    q1.push(tmp);
    q2.pop();
  }
  return 0;
}