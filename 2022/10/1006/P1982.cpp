#include<bits/stdc++.h>
#define ll __int128
using namespace std;

const ll N = 1e6 + 5;

inline ll read(){
  ll s = 0 , f = 1;
  char ch = getchar();
  while(ch < '0' || ch > '9'){
    if(ch == '-'){
      f = -1;
    }
    ch = getchar();
  }
  while(ch >= '0' && ch <= '9'){
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * f;
}
inline void write(ll x){
  if(x < 10){
    char ch = x + '0';
    putchar(ch);
    return ;
  }
  write(x / 10);
  char ch = x % 10 + '0';
  putchar(ch);
  return ;
}
inline ll llmax(ll x , ll y){return (x > y ? x : y);}
inline ll llmin(ll x , ll y){return (x < y ? x : y);}
inline ll abss(ll x){return (x < 0 ? -x : x);}

ll a[N] , b[N] , c[N] , f[N] , s[N];
ll ans = -1e32;

int main(){
  ll n = read() , mod = read();
  for(ll i = 1 ; i <= n ; i++){
    a[i] = read();
  }
  b[1] = f[1] = s[1] = a[1];
  for(ll i = 2 ; i <= n ; i++){
    f[i] = llmax(f[i-1] + a[i] , a[i]);
    b[i] = llmax(b[i-1] , f[i]);
  }
  // for(ll i = 1 ; i <= n ; i++){
  //   write(abss(f[i]));
  //   cout<<endl;
  // }
  c[1] = b[1];
  s[1] = b[1] + c[1];
  ans = c[1];
  for(ll i = 2 ; i <= n ; i++){
    c[i] = s[i-1];
    s[i] = llmax(s[i-1] , c[i] + b[i]);
    ans = max(ans , c[i]);
    // write(abss(ans));
    // cout<<endl;
  }
  // for(ll i = 1 ; i <= n ; i++){
  //   write(abss(c[i]));
  //   cout<<endl;
  // }
  if(ans > 0){
    ans = ans % mod;
  }
  else{
    cout<<'-';
    ans = abss(ans) % mod;
  }
  write(ans);
  return 0;
}