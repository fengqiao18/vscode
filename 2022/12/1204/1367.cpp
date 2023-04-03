#include<bits/stdc++.h>
using namespace std;
const int N = 105;
struct node {
  int d;
  int left;
  int right;
} q[N];
int n, a;
int ans;
void helper(int k) {
  if (q[k].left){
    helper(q[k].left);
  }
  ans++;
  if (q[k].d == a) {
    cout << ans << endl;
    exit(0);
  }
  if (q[k].right){
    helper(q[k].right);
  }
  return ;
}
int main() {
  cin >> n >> a;
  for (int i = 1; i <= n; i++){
    cin >> q[i].d >> q[i].left >> q[i].right;
  }
  helper(1);
  return 0;
}