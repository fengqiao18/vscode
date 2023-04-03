#include<bits/stdc++.h>
using namespace std;
stack<int> stk;
int n;
long long ans;
int main(){
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    int x;
    cin>>x;
    while(!stk.empty() && stk.top() <= x){
      stk.pop();
    }
    ans += stk.size();
    stk.push(x);
  }
  cout<<ans;
  return 0;
}