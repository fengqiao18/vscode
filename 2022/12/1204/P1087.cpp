#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
string s;
char get_fbi(string s) {
  int cnt = 0;
  for (int i = 0; i < s.size(); i++){
    cnt += (s[i] == '0');
  }
  if (cnt == 0){
    return 'I';
  }
  else if (cnt == s.size()){
    return 'B';
  }
  return 'F';
}
void dfs(string s) {
  if (s.size() == 1) {
    cout << get_fbi(s);
    return;
  }
  int len = s.size();
  dfs(s.substr(0, len / 2));
  dfs(s.substr(len / 2));
  cout << get_fbi(s);
  return ;
}
int main() {
  cin >> n >> s;
  dfs(s);
  return 0;
}