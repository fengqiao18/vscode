#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int n;
bool vis[5] , ans[N];
string a[N] , arr[N];
void update(string s){
  for(int i = 1 ; i <= n ; i++){
    if(arr[i] == s){
      ans[i] = 1;
    }
  }
  return ;
}
void dfs(int cur , string s){
  update(s);
  if(cur == 5){
    return ;
  }
  for(int i = 1 ; i <= 4 ; i++){
    if(!vis[i]){
      vis[i] = 1;
      for(int j = 0 ; j <= 5 ; j++){
        dfs(cur + 1 , s + a[i][j]);
      }
      vis[i] = 0;
    }
  }
}
int main(){
  cin>>n;
  for(int i = 1 ; i <= 4 ; i++){
    cin>>a[i];
  }
  for(int i = 1 ; i <= n ; i++){
    cin>>arr[i];
  }
  dfs(1 , "");
  for(int i = 1 ; i <= n ; i++){
    cout<<(ans[i] ? "YES" : "NO")<<endl;
  }
  return 0;
}