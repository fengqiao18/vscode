#include<bits/stdc++.h>
using namespace std;
const int N = 105;
const int dx[] = {0 , -1 , 1 , 0 , 0 , -1 , 1 , -1 , 1};
const int dy[] = {0 , 0 , 0 , -1 , 1 , -1 , -1 , 1 , 1};
char a[N][N];
int count(int x , int y){
  int cnt = 0;
  for(int i = 1 ; i <= 8 ; i++){
    cnt += a[x+dx[i]][y+dy[i]] == '*';
  }
  return cnt;
}
int main(){
  int n , m;
  cin>>n>>m;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      cin>>a[i][j];
    }
  }
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      if(a[i][j] == '*'){
        cout<<'*';
      }
      else{
        cout<<count(i , j);
      }
    }
    cout<<endl;
  }
  return 0;
}