#include<bits/stdc++.h>
using namespace std;
int num(int a , int b , int c){
	return a * 100 + b * 10 + c;
}
int main(){
	string s;
	cin>>s;
	int n = s.size();
	s = '*' + s;
	int v0 = s.find('0');
	if(v0 < n){
		cout<<0;
		return 0;
	}
	for(int i = 1 ; i <= n ; i++){ 
		int x = s[i] - '0';
		for(int j = i + 1 ; j <= n ; j++){
			int y = s[j] - '0';
			for(int k = j + 1 ; k <= n ; k++){
				int z = s[k] - '0';
				if(num(x , y , z) % 8 == 0){
					cout<<"YES"<<endl<<x<<y<<z;
					return 0;
				}
			}
			if(num(0 , x , y) % 8 == 0){
				cout<<"YES"<<endl<<x<<y;
				return 0;
			}
		}
		if(x % 8 == 0){
			cout<<"YES"<<endl<<x;
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}

