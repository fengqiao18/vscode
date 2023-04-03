#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
bool vis[N];
int d , n;
int pos;
void helper(){
  pos = 1;
  for(int i = 2 ; i <= d ; i++){
    if(vis[pos]){
      vis[pos] = 0;
      pos = pos * 2 + 1;
    }
    else{
      vis[pos] = 1;
      pos = pos * 2;
    }
  }
  return ;
}
int main(){
  cin>>d>>n;
  for(int i = 1 ; i <= n ; i++){
    helper();
  }
  cout<<pos;
  return 0;
}