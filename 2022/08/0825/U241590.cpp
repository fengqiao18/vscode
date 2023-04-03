#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
const int inf = 1e9;
const long long inf2 = 1e18;
int n;
struct D{
  int xl , yl , xr , yr;
};
D pd[N] , sd[N];
pair<int , int> p[N];
long long ans = inf2;
int main(){
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    cin>>p[i].first>>p[i].second;
  }
  pd[0].xl = pd[0].yl = sd[n + 1].xl = sd[n + 1].yl = inf;
  for(int i = 1 ; i <= n ; i++){
    pd[i].xl = min(pd[i - 1].xl, p[i].first), pd[i].xr = max(pd[i - 1].xr, p[i].first);
    pd[i].yl = min(pd[i - 1].yl, p[i].second), pd[i].yr = max(pd[i - 1].yr, p[i].second);
  }
  for(int i = n ; i >= 1 ; i--){
    sd[i].xl = min(sd[i + 1].xl, p[i].first), sd[i].xr = max(sd[i + 1].xr, p[i].first);
    sd[i].yl = min(sd[i + 1].yl, p[i].second), sd[i].yr = max(sd[i + 1].yr, p[i].second);
  }
  for(int i = 1 ; i <= n ; i++){
    long long lx = max(pd[i - 1].xr, sd[i + 1].xr) - min(pd[i - 1].xl, sd[i + 1].xl);
    long long ly = max(pd[i - 1].yr, sd[i + 1].yr) - min(pd[i - 1].yl, sd[i + 1].yl);
    ans = min(ans , lx * ly);
  }
  cout<<ans;
  return 0;
}