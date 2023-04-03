#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct node {
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
};
node h;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    h.push(x);
  }
  long long sum = 0;
  for (int i = 1; i < n; i++) {
    int x = h.top();
    h.pop();
    int y = h.top();
    h.pop();
    int tmp = x + y;
    h.push(tmp);
    sum += tmp;
    // cout << tmp << endl;
  }
  cout << sum;
  return 0;
}