#include <bits/stdc++.h>
using namespace std;
struct Node {
  int lt, rt;
  char val;
};
Node node[1005];
int cnt;
char gc() { return getchar(); }
int in(char val) {
  if (val == '.') {
    return 0;
  }
  int tmp = ++cnt;
  node[tmp].val = val;
  node[tmp].lt = in(gc());
  node[tmp].rt = in(gc());
  return tmp;
}
void zhong(int r) {
  if (r == 0) {
    return;
  }
  zhong(node[r].lt);
  cout << node[r].val;
  zhong(node[r].rt);
  return;
}
void hou(int r) {
  if (r == 0) {
    return;
  }
  hou(node[r].lt);
  hou(node[r].rt);
  cout << node[r].val;
  return;
}
int main() {
  int root = in(gc());
  zhong(root);
  cout << endl;
  hou(root);
  return 0;
}