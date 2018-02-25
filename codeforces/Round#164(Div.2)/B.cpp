#include<bits/stdc++.h>
using namespace std;
long long n,ans;
//long long ans[2005];
int main(){
	cin>>n;
	for(long long i = 0;i<n;i++){
		ans+=(n-i)*(i+1)-i;
	}
	cout<<ans<<endl;
	return 0;
}
