#include<bits/stdc++.h>
using namespace std;
const int N = 15;
struct node{
  int x , y , b;
};
node p[N];
int n , ans = 0;
int check(int i, int j){
  if (p[i].x == p[j].x) {
    return p[i].y > p[j].y;
  }
  if (p[i].y == p[j].y) {   
    return (p[i].x > p[j].x) + 2;
  }
  return -1;
}
void dfs(int x , int d , int l){
  if(!x && l){
    ans += (l == n+1 ? 1 : 0);
    return ;
  }
  for(int i = 0 ; i <= n ; i++){
    int _d = check(x , i);
    if (_d != -1 && _d != d && !p[i].b) {
      p[i].b = 1; 
      dfs(i, _d, l + 1);  
      p[i].b = 0;         
    }
  }
}
int main(){
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    cin>>p[i].x>>p[i].y;
  }
  dfs(0 , -1 , 0);
  cout<<ans;
  return 0;
}