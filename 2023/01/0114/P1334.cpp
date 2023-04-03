#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
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
small_node pq;
int a[N], n;
long long ans;  

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pq.push(a[i]);
  }  
  for (int i = 1; i <= n - 1; i++) {
    int a = pq.top();  
    pq.pop();
    int b = pq.top();  
    pq.pop();
    int tmp = a + b;
    ans += tmp;   
    pq.push(tmp);  
  }
  cout << ans;  
  return 0;             
}
