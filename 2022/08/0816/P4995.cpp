#include<bits/stdc++.h>
using namespace std;
const int N = 305;
long long a[N] , ans = 0;
int main(){
  int n;
  cin>>n;
  for(int i = 1 ; i <= n ; i++)
    cin>>a[i];
  sort(a+1 , a+1+n);
  for(int i = 0 , j = n ; i < j ; i++ , j--){
    ans += pow(a[j] - a[i] , 2);
    ans += pow(a[j] - a[i+1] , 2);
  }
  cout<<ans;
}