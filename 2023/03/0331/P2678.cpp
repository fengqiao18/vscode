#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N];
int l , n , m;
bool check(int x){
	int cnt = 0 , s = 0;
	for(int i = 1 ; i <= n + 1 ; i++){
		if(a[i] - s < x){
			cnt++;
		}
		else{
			s = a[i];
		}
	}
	return cnt <= m;
}
int main(){
	cin>>l>>n>>m;
	for(int i = 1 ; i <= n ; i++){
		cin>>a[i];
	}
	a[n + 1] = l;
	int lt = 0 , rt = l + 1;
	while(lt + 1 < rt){
		int mid = (lt + rt) >> 1;
		if(check(mid)){
			lt = mid;
		}
		else{
			rt = mid;
		}
	}
	cout<<lt;
	return 0;
}

