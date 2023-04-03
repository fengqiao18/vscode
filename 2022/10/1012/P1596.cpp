#include<bits/stdc++.h>
using namespace std;
const int N = 105;
const int dx[] = {0, 0, 0, -1, 1 , -1 , -1 , 1 , 1};
const int dy[] = {0, -1, 1, 0, 0 , -1 , 1 , -1 , 1};
bool vis[N][N];
int a[N][N];
int n , m;
void dfs(int x , int y){
  if(x < 1 || y < 1 || x > n || y > m || vis[x][y] || a[x][y] == 0){return ;}
  // cout<<x<<" "<<y<<endl;
  vis[x][y] = 1;
  for(int i = 1 ; i <= 8 ; i++){
    dfs(x + dx[i] , y + dy[i]);
  }
  return ;
}
int main(){
  cin>>n>>m;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      char c;
      cin>>c;
      a[i][j] = (c == '.' ? 0 : 1);
    }
  }
  int cnt = 0;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      if(a[i][j] == 1 && !vis[i][j]){
        // cout<<"-----------------------------"<<endl;
        dfs(i , j);
        cnt++;
      }
    }
  }
  cout<<cnt;
  return 0;
}