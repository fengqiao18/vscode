#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
int n , q;
int erfen(int x){
	int lt = 0 , rt = n + 1;
	while(lt + 1 < rt){
		int mid = (lt + rt) >> 1;
		if(a[mid] < x){
			lt = mid;
		}
		else{
			rt = mid;
		}
	}
	return rt;
} 
int main(){
	cin>>n;
	for(int i = 1 ; i <= n ; i++){
		cin>>a[i];
	} 
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		cout<<erfen(x) - 1<<endl;
	}
	return 0;
}

