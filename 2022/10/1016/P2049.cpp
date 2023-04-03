#include<bits/stdc++.h>
using namespace std;
const int N = 105;
const int dx[] = {0 , 0 , 1};
const int dy[] = {0 , 1 , 0};
struct node{
  int x , y , num;
};
bool vis[N][N][N] , ans[N];
int n , m , p;
int a[N][N];
void bfs(){
  queue<node> q;
  node cur = {1 , 1 , a[1][1]};
  vis[1][1][a[1][1]] = 1;
  q.push(cur);
  while(!q.empty()){
    cur = q.front();
    q.pop();
    if(cur.x == n && cur.y == m){
      ans[cur.num] = 1;
      continue;
    }
    for(int i = 1 ; i <= 2 ; i++){
      int xx = cur.x + dx[i] , yy = cur.y + dy[i] , nnum = (a[xx][yy] * cur.num) % p;
      if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && !vis[xx][yy][nnum]){
        // cout<<xx<<" "<<yy<<endl;
        node tmp = {xx , yy , nnum};
        q.push(tmp);
        vis[xx][yy][nnum] = 1;
      }
    }
  }
}
int main(){
  cin>>n>>m>>p;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      cin>>a[i][j];
      a[i][j] %= p;
    }
  }
  bfs();
  int cnt = 0;
  for(int i = 0 ; i < p ; i++){
    cnt += ans[i];
  }
  cout<<cnt<<endl;
  for(int i = 0 ; i < p ; i++){
    if(ans[i]){
      cout<<i<<" ";
    }
  }
  return 0;
}