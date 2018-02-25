#include<bits/stdc++.h>
using namespace std;
int n,ans;
int h[50],g[50];
int main(){
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>h[i]>>g[i];
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(i!=j && h[i] == g[j]){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
