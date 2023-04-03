#include<bits/stdc++.h>
using namespace std;
const int N = 405;
struct node{
  int x , y , num;
};
node a[N];
int cnt;
bool cmp(node x , node y){
  return x.num > y.num;
}
int main(){
  int n , m , k;
  cin>>n>>m>>k;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= m ; j++){
      int tmp;
      cin>>tmp;
      if(tmp > 0){
        cnt++;
        a[cnt] = {i , j , tmp};
      }
    }
  }
  sort(a+1 , a+1+cnt , cmp);
  node now = {0 , a[1].y , 0};
  int ans = 0;
  for(int i = 1 ; i <= cnt ; i++){
    if(now.num + abs(now.x - a[i].x) + abs(now.y - a[i].y) + 1 + a[i].x > k){
      cout<<ans;
      return 0;
    }
    now.num += abs(now.x - a[i].x) + abs(now.y - a[i].y) + 1;
    now.x = a[i].x , now.y = a[i].y;
    ans += a[i].num;
  }
  cout<<ans;
  return 0;
}