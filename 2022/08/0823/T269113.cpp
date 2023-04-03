#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N] , b[N];
int ans = 0;
string s;
int main(){
  cin>>s;
  int n = s.size();
  for(int i = 1 ; i <= n ; i++){
    a[i] = a[i-1] + (s[i-1] == '(' ? 1 : -1);
  }
  for(int i = n ; i >= 1 ; i--){
    b[i] = i == n ? a[i] : min(a[i] , b[i+1]);
  }
  for(int i = 1 ; i <= n && a[i-1] >= 0 ; i++){
    if(s[i-1] == '('){
      ans += b[i] >= 2 && a[n] == 2;
    }
    else{
      ans += b[i] >= -2 && a[n] == -2;
    }
  }
  cout<<ans;
  return 0;
}