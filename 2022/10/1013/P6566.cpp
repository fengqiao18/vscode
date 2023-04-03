#include<bits/stdc++.h>
using namespace std;
const int dx[]={0 , 0 , 1 , 0 , -1 , 1 , 1 , -1 , -1};
const int dy[]={0 , 1 , 0 , -1 , 0 , 1 , -1 , 1 , -1};
const int N = 1500 + 5;
int ans[(int)(1e5 + 5)];
int size , maxi = -1e9;
bool vis[N][N];
char a[N][N];
int n , m;
void dfs(int x , int y){
  if(x < 1 || y < 1 || x > n || y > m || vis[x][y] || a[x][y] == '.'){
    return ;
  }
  size++ , vis[x][y] = 1;
  for(int i = 1 ; i <= 8 ; i++){
    dfs(x + dx[i] , y + dy[i]);
  }
}
int main(){
  cin>>n>>m;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      cin>>a[i][j];
    }
  }
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      if(a[i][j] == '*' && !vis[i][j]){
        size = 0;
        dfs(i , j);
        ans[size]++;
      }
    }
  }
  for(int i = 1 ; i <= 1e5 ; i++){
    if(ans[i] > 0){
      ans[0]++ , maxi = max(maxi , ans[i] * i);
    }
  }
  cout<<ans[0]<<" "<<maxi;
  return 0;
}