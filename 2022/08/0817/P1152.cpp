#include<bits/stdc++.h>
using namespace std;
const int N = 1005 , K = 1e8 + 5;
long long a[N] , cnt[K];
int main(){
  int n;
  cin>>n;
  for(int i = 1 ; i <= n ; i++)
    cin>>a[i];
  for(int i = 1 ; i < n ; i++){
    long long x = llabs(a[i] - a[i+1]);
    cnt[x]++;
  }
  for(int i = 1 ; i < n ; i++){
    if(cnt[i] == 0){
      cout<<"Not jolly";
      return 0;
    }
  }
  cout<<"Jolly";
  return 0;
}