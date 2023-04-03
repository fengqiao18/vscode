#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
int t1[N] , t2[N];
int main(){
  string s;
  cin>>s;
  if(s == "0"){
    cout<<0;
    return 0;
  }
  int n = s.size() - 1;
  t1[n+1] = t1[n+2] = t1[n+3] = t1[n+4] = 0;
  for(int i = n ; i >= 0 ; i--){
    t1[i] = s[n-i] - '0';
    t2[i+4] = s[n-i] - '0';
  }
  t2[0] = t2[1] = t2[2] = t2[3] = 0;
  int last = 0;
  int ans[N] , cnt = 0;
  for(int i = 0 ; i <= n + 10 ; i++){
    if(t1[i] + t2[i] == 1){
      if(last == 1){
        ans[++cnt] = 0;
        last = 1;
      }
      else{
        ans[++cnt] = 1;
        last = 0;
      }
    }
    else if(t1[i] + t2[i] == 2){
      ans[++cnt] = last;
      last = 1;
    }
    else{
      if(last == 0 && i >= n+4){
        break;
      }
      ans[++cnt] = last;
      last = 0;
    }
  }
  bool flag = 0;
  for(int i = cnt ; i >= 1 ; i--){
    if(flag && ans[i] <= 0){
      cout<<0;
    }
    else if(ans[i] != 0){
      flag = 1;
      cout<<ans[i];
    }
    else{
      continue;
    }
  }
  return 0;
}