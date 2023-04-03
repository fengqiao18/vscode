#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
const int mve = 1001;
const int dx[] = {0 , 0 , 1 , 1 , 0 , -1 , -1};
const int dy[] = {0 , 1 , 1 , 0 , -1 , -1 , 0};
struct node{
  int x , y;
};
node a[N];
bool vis[N][N] , mp[N][N];
void dfs(int x , int y){
  if(x < 1 || x > 2001 || y < 1 || y > 2001 || vis[x][y] || !mp[x][y]){
    return ;
  }
  vis[x][y] = 1;
  for(int i = 1 ; i <= 6 ; i++){
    int xx = x + dx[i] , yy = y + dy[i];
    dfs(xx , yy);
  }
  return ;
}
int main(){
  int n;
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    cin>>a[i].x>>a[i].y;
    a[i].x += mve , a[i].y += mve;
    mp[a[i].x][a[i].y] = 1;
  }
  int ans = 0;
  for(int i = 1 ; i <= n ; i++){
    if(!vis[a[i].x][a[i].y]){
      dfs(a[i].x , a[i].y);
      ans++;
    }
  }
  cout<<ans;
  return 0;
}