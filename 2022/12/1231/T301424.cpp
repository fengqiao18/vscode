#include <bits/stdc++.h>
using namespace std;
inline int helper(int n){
  if(n % 2 == 0){
    return -1;
  }
  if(n == 1){
    return 1;
  }
  long long cnt = 1 , ans = 0;
  while(cnt < n){
    ans++;
    cnt <<= 1;
  }
  return ans;
}
int main() {
  // freopen("1.out" , "w" , stdout);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << helper(n) << '\n';
  }
  return 0;
}