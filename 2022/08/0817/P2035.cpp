#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N];
int main(){
  int n , t;
  cin>>n>>t;
  for(int i = 1 ; i <= n ; i++)
    cin>>a[i];
  int now = 1;
  int maxi = -1e9 , vis;
  for(int i = 1 ; i <= n ; i++){
    if(a[i] > maxi){
      maxi = a[i];
      vis = i;
    }
  }
  now = vis;
  while(t--){
    cout<<now<<endl;
    int yu = a[now] % (n - 1);
    int pin = (a[now] - yu) / (n - 1);
    for(int i = 1 ; i <= n ; i++){
      if(i != now){
        a[i] += pin;
        if(yu != 0)
          a[i]++ , yu--;
      }
    }
    a[now] = 0;
    int maxi = -1e9 , vis;
    for(int i = 1 ; i <= n ; i++){
      if(a[i] > maxi){
        maxi = a[i];
        vis = i;
      }
    }
    now = vis;
  }
  return 0;
}