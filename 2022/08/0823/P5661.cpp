#include<bits/stdc++.h>
using namespace std;
struct node{
  int id , p , t;
};
const int N = 1e5 + 5;
bool vis[N];
deque<node> q;
int main(){
  int n , ans = 0;
  cin>>n;
  for(int i = 1 ; i <= n ; i++){
    int op , p , t;
    cin>>op>>p>>t;
    if(op == 0){
      ans += p;
      node cur;
      cur.id = i , cur.p = p , cur.t = t;
      q.push_back(cur);
      while(!q.empty() & t - q.front().t > 45){
        q.pop_front();
      }
    }
    else{
      for(int i = 0 ; i < q.size() ; i++){
        node cur = q[i];
        if(!vis[cur.id] && t - cur.t <= 45 && p <= cur.p){
          vis[cur.id] = 1;
          p = 0;
          break;
        }
      }
      ans = ans + p;
    }
  }
  cout<<ans;
  return 0;
}