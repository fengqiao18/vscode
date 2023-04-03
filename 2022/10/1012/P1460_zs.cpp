#include<bits/stdc++.h>
using namespace std;
const int N = 30;
int v[N] , g[N][N];
int vis[N] , as[N];
int V , G , ans = 1e9;
bool check(int x){
  for(int i = 1 ; i <= V ; i++){
    int tmp = 0;
    for(int j = 1 ; j <= x ; j++){
      tmp += g[as[j]][i];
    }
    if(tmp < v[i]){
      return 0;
    }
  }
  return 1;
}
void update(int cnt){
  ans = cnt;
  for(int i = 1 ; i <= cnt ; i++){
    vis[i] = as[i];
  }
  return ;
}
void dfs(int cur , int cnt){
  if(cur > G){
    if(cnt < ans && check(cnt)){
      update(cnt);
    }
    return ;
  }
  as[cnt+1] = cur;
  dfs(cur+1 , cnt+1);
  dfs(cur+1 , cnt);
  return ;
}
int main(){
  cin>>V;
  for(int i = 1 ; i <= V ; i++){
    cin>>v[i];
  }
  cin>>G;
  for(int i = 1 ; i <= G ; i++){
    for(int j = 1 ; j <= V ; j++){
      cin>>g[i][j];
    }
  }
  dfs(1 , 0);
  cout<<ans<<" ";
  for(int i = 1 ; i <= ans ; i++){
    cout<<vis[i]<<" ";
  }
  return 0;
}