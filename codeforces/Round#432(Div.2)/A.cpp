#include<bits/stdc++.h>
using namespace std;
int n,k,t;
int main(){
	cin>>n>>k>>t;
	if(t<=k) cout<<t<<endl;
	else if(t<=n) cout<<k;
	else cout<<k+n-t;
	return 0;
} 
