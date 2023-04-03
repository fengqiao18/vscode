#include<bits/stdc++.h>
using namespace std;
const int N = 105;
bool vis[N];
int main(){
  int n , ans = 0;
  string s;
  cin>>n>>s;
  for(int i = 0 ; i <= n - 3 ; i++){
    if(s[i] == 'x' && s[i+1] == 'x' && s[i+2] == 'x'){
      vis[i] = 1;
    }
  }
  for(int i = 0 ; i < n ; i++){
    ans += vis[i];
  }
  cout<<ans;
  return 0;
}