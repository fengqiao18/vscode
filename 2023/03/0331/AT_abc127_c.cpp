#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int diff[N] , a[N];
int main(){
	int n , m;
	cin>>n>>m;
	for(int i = 1 ; i <= m ; i++){
		int l , r;
		cin>>l>>r;
		diff[l]++ , diff[r + 1]--;
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; i++){
		a[i] = a[i - 1] + diff[i];
		//cout<<a[i]<<" ";
		if(a[i] == m){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
