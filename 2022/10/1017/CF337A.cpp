#include<bits/stdc++.h>
using namespace std;
const int N = 55;
int a[N];
int main(){
  int n , m;
  cin>>n>>m;
  for(int i = 1 ; i <= m ; i++){
    cin>>a[i];
  }
  int mini = 1e9;
  sort(a+1 , a+1+m);
  for(int i = 1 , j = n ; j <= m ; i++ , j++){
    mini = min(mini , a[j] - a[i]);
    // cout<<mini<<endl;
  }
  cout<<mini;
  return 0;
}