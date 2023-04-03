#include<bits/stdc++.h>
using namespace std;
const int N = 25;
int ans = 0;
const int dx[] = {0, 0, 0, -1, 1};
const int dy[] = {0, -1, 1, 0, 0};
bool vis[N][N];
char a[N][N];
int sx , sy;
int n , m;
void dfs(int x , int y){
  if(x < 1 || y < 1 || x > n || y > m || vis[x][y] || a[x][y] == '#'){
    return ;
  }
  // cout<<x<<" "<<y<<endl;
  vis[x][y] = 1;
  ans++;
  for(int i = 1 ; i <= 4 ; i++){
    // if(x == sx && y == sy){
    //   cout<<x+dx[i]<<" "<<y+dy[i]<<" "<<vis[x+dx[i]][y+dy[i]]<<endl;
    // }
    dfs(x+dx[i] , y+dy[i]);
  }
  return ;
}
int main(){
  cin>>m>>n;
  for(int i = 1 ; i <= n ; i++){
    // cout<<i;
    for(int j = 1 ; j <= m ; j++){
      cin>>a[i][j];
      if(a[i][j] == '@'){
        // cout<<i<<" "<<j<<endl;
        sx = i , sy = j;
      }
    }
  }
  // cout<<sx<<" "<<sy<<endl;
  dfs(sx , sy);
  cout<<ans;
  return 0;
}