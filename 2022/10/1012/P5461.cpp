#include<bits/stdc++.h>
using namespace std;
const int N = (1 << 10) + 5;
int a[N][N] , n;
void init(int size){
  for(int i = 1 ; i <= size ; i++){
    for(int j = 1 ; j <= size ; j++){
      a[i][j] = 1;
    }
  }
  return ;
}
void print(int size){
	for(int i = 1 ; i <= size ; i++){
		for(int j = 1 ; j <= size ; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return ;
}
void helper(int n , int x , int y){//边长，左上坐标点
	if(n == 0){
		return ;
	}
	for(int i = x ; i <= x + n / 2 - 1 ; i++){
		for(int j = y ; j <= y + n / 2 - 1 ; j++){
			a[i][j] = 0;
		}
	}
	helper(n/2 , x + n / 2 , y);
	helper(n/2 , x , y + n / 2);
	helper(n/2 , x + n / 2 , y + n / 2);
	return ;
}
int main(){
  cin>>n;
	int size = 1 << n;
	init(size);
	helper(size , 1 , 1);
	print(size);
	return 0;
}