#include<bits/stdc++.h>
using namespace std;
int n;
string s;
map<string , int> mp;
int main(){
  cin>>n>>s;
  for(int len = 1 ; len <= n ; len++){
    bool flag = 0;
    for(int i = 0 ; i + len - 1 < s.size() ; i++){
      string tmp = s.substr(i , len);
      if(mp[tmp] == 1){
        flag = 1;
        break;
      }
      else{
        mp[tmp] = 1;
      }
    }
    if(!flag){
      cout<<len;
      exit(0);
    }
  }
  return 0;
}