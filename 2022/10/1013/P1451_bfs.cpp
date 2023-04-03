#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int dx[] = {0, 0, 0, -1, 1};
const int dy[] = {0, -1, 1, 0, 0};
int n, m;
char a[N][N];
bool vis[N][N];
struct node{
  int x , y;
};
void bfs(int sx, int sy) {
  queue<node> q;
  node cur = {sx , sy};
  q.push(cur);
  while(!q.empty()){
    cur = q.front();
    q.pop();
    for(int i = 1 ; i <= 4 ; i++){
      int xx = cur.x + dx[i] , yy = cur.y + dy[i];
      if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && !vis[xx][yy] && a[xx][yy] != '0'){
        node tmp = {xx , yy};
        q.push(tmp);
        vis[xx][yy] = 1;
      }
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] != '0' && !vis[i][j]) {
        bfs(i, j);
        cnt++;
      }
    }
  }
  cout << cnt;
  return 0;
}