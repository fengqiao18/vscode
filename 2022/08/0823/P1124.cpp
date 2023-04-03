#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
char s[N] ,  sorted[N] , ans[N];
bool vis[N];
int n , p , cur;
int main(){
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    cin>>s[i];
    sorted[i] = s[i];
  }
  cin>>p;
  sort(sorted+1 , sorted+1+n);
  ans[1] = s[p];
  for(int i = 1 ; i <= n ; i++){
    if(sorted[i] == s[p]){
      cur = i;
      break;
    }
  }
  for(int i = n ; i >= 2 ; i--){
    vis[cur] = 1;
    ans[i] = s[cur];
    for(int j = n ; j >= 1 ; j--){
      if(sorted[j] == s[cur] && vis[j] == 0){
        cur = j;
        break;
      }
    }
  }
  for(int i = 1 ; i <= n ; i++){
    cout<<ans[i];
  }
  return 0;
}