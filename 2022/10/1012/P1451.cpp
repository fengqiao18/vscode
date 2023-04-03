#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const int dx[] = {0, 0, 0, -1, 1};
const int dy[] = {0, -1, 1, 0, 0};

int n , m;
char a[N][N];
bool vis[N][N];
void dfs(int x , int y){
  if(x < 1 || x > n || y < 1 || y > m || vis[x][y] || a[x][y] == '0'){return ;}
  vis[x][y] = 1;
  for(int i = 1 ; i <= 4 ; i++){
    dfs(x + dx[i] , y + dy[i]);
  }
  return ;
}
int main(){
  cin>>n>>m;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      cin>>a[i][j];
    }
  }
  int cnt = 0;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      if(!vis[i][j] && a[i][j] != '0'){
        dfs(i , j);
        cnt++;
      }
    }
  }
  cout<<cnt;
  return 0;
}