#include<bits/stdc++.h>
using namespace std;
int main(){
  int n , p , a;
  cin>>n>>p>>a;
  long long sum = max(a , 0) , maxx = a , maxn = a * 2;
  bool flag = a > 0 && n > 1;
  for(n -= 2 ; n-- >= 0 ; sum = max(sum , 0ll)){
    // cout<<1;
    int c;
    cin>>c;
    sum += c;
    maxn += max(maxx = max(maxx , sum) , 0ll);
    if(flag){
      maxn %= p;
    }
    else if(maxn > a){
      flag = 1;
    }
  }
  maxn = (flag ? maxn : a);
  if(maxn < 0){
    cout<<"-";
  }
  cout<<abs(maxn) % p;
  return 0;
}