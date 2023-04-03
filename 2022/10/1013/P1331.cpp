#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int dx[] = {0, 0, 0, -1, 1};
const int dy[] = {0, -1, 1, 0, 0};
int n , m;
char a[N][N];
bool vis[N][N];
bool check(int x , int y){
  if(x-1 < 1 || y-1 < 1){return 0;}
  int ans = (a[x-1][y] == '#') + (a[x][y-1] == '#') + (a[x-1][y-1] == '#') + (a[x][y] == '#');
  return ans == 3;
}
void dfs(int x, int y) {
  if (x < 1 || y < 1 || x > n || y > m || vis[x][y] || a[x][y] == '.') {
    return;
  }
  vis[x][y] = 1;
  for (int i = 1; i <= 4; i++) {
    dfs(x + dx[i], y + dy[i]);
  }
  return;
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
      if(check(i , j)){
        cout<<"Bad placement.";
        return 0;
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] != '.' && !vis[i][j]) {
        dfs(i, j);
        cnt++;
      }
    }
  }
  cout <<"There are " <<cnt<<" ships.";
  return 0;
}