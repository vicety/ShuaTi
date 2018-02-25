#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll ans;
ll g[55][55];
ll wline[55],wrow[55],bline[55],brow[55],cntb,cntw;
int main(){
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cin>>g[i][j];
			if(g[i][j]) bline[j]++,brow[i]++,cntb++;
			else wline[j]++,wrow[i]++,cntw++;
		}
	}
	for(int i = 0;i<n;i++){
		ans+=(1LL<<wrow[i])-1;
		ans+=(1LL<<brow[i])-1;
	}
	for(int i = 0;i<m;i++){
		ans+=(1LL<<wline[i])-1;
		ans+=(1LL<<bline[i])-1;
	}
	ans-=cntb;
	ans-=cntw;
	cout<<ans;
	return 0;
}
