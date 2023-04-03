#include<bits/stdc++.h>
using namespace std;
const int N = 1025 , M = 2049;
char c[N][M];
int main(){
  int n , len = 4;
  cin>>n;
  n--;
  for(int i = 1 ; i <= 1<<10 ; i++){
    for(int j = 1 ; j <= 1<<11 ; j++){
      c[i][j] = ' ';
    }
  }
  c[1][1] = c[2][2] = '/';
  c[1][2] = c[1][3] = '_';
  c[1][4] = c[2][3] = '\\';
  while(n--){
    for(int i = 1 ; i <= len / 2 ; i++){
      for(int j = 1 ; j <= len ; j++){
        c[i+(len/2)][j+(len/2)] = c[i][j+len] = c[i][j];
      }
    }
    len <<= 1;
  }
  for(int i = len/2 ; i >= 1 ; i--){
    for(int j = 1 ; j <= len ; j++){
      cout<<c[i][j];
    }
    cout<<'\n';
  }
  return 0;
}