#include<bits/stdc++.h>
using namespace std;
long long l,r,x,y,q;
double mmin,mmax;
int main(){
	cin>>l>>r>>x>>y;
	cin>>q;
	for(int i = x;i<=y;i++){
		if(q*i>=l && q*i<=r){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
} 
