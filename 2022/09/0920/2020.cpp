#include<bits/stdc++.h>
using namespace std;
int main(){
  int m;
  cin>>m;
  int s = 0 , cnt = 1;
  while(s <= m){
    s += cnt;
    cnt++;
  }
  cout<<cnt-1;
  return 0;
}