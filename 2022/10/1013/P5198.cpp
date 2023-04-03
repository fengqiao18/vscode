#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
const int dx[] = {0 , -1 , 1 , 0 , 0};
const int dy[] = {0 , 0 , 0 , -1 , 1};
int n , c1 , c2;
bool vis[N][N];
char a[N][N];
int cir(int x , int y){
  int cnt = 0;
  for(int i = 1 ; i <= 4 ; i++){
    int xx = x + dx[i] , yy = y + dy[i];
    if(a[xx][yy] == '.'){
      cnt++;
    }
  }
  return cnt;
}
void dfs(int x , int y){
  if(x < 1 || x > n || y < 1 || y > n || vis[x][y] || a[x][y] == '.'){
    return ;
  }
  vis[x][y] = 1;
  c1++ , c2 += cir(x , y);
  for(int i = 1 ; i <= 4 ; i++){
    dfs(x+dx[i] , y+dy[i]);
  }
  return ;
}
int main(){
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= n ; j++){
      cin>>a[i][j];
    }
  }
  for(int i = 0 ; i <= n+1 ; i++){
    a[0][i] = '.';
    a[i][0] = '.';
    a[n+1][i] = '.';
    a[i][n+1] = '.';
  }
  int ans1 = -1e9 , ans2 = -1e9;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= n ; j++){
      if(a[i][j] == '#' && !vis[i][j]){
        c1 = 0 , c2 = 0;
        dfs(i , j);
        if(c1 > ans1){
          ans1 = c1 , ans2 = c2;
        }
        if(c1 == ans1){
          ans2 = c2;
        }
      }
    }
  }
  cout<<ans1<<" "<<ans2;
  return 0;
}