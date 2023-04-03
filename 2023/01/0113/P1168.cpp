#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
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
};
small_node q2;
int main() {
  int n, tmp;
  cin >> n >> tmp;
  q1.push(tmp);
  cout << q1.top() << endl;
  for (int i = 2; i <= n; i++) {
    int input;
    cin >> input;
    if (input > q1.top()){
      q2.push(input);
    }
    else{
      q1.push(input);
    }
    while (abs(q1.size() - q2.size()) > 1)
      if (q1.size() > q2.size()) {
        int tmp = q1.top();
        q2.push(tmp);
        q1.pop();
      } else {
        int tmp = q2.top();
        q1.push(tmp);
        q2.pop();
      }
    if (i % 2) {
      cout << (q1.size() > q2.size() ? q1.top() : q2.top()) << endl;
    }
  }
  return 0;
}