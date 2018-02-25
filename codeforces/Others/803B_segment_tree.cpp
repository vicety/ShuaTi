#include<bits/stdc++.h>
using namespace std;
const int maxn = 110000;
int tmp,num[maxn],pos;
vector<int> x[maxn];
int cur,n;
void add(int k1,int k2){
	for (;k1<=n;k1+=k1&(-k1)) num[k1]+=k2;
}
int find(int k1){
	int ans=0;
	for (;k1;k1-=k1&(-k1)) ans+=num[k1]; return ans;
}
int calc(int l,int r){
	if (l>r) return calc(l,n)+calc(0,r);
	return find(r)-find(l);
}
int main(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		add(i,1);
		scanf("%d",&tmp);
		x[tmp].push_back(i);
		
	}
	int pre=0; long long ans=0;
	for(int i = 1;i<=100000;i++){
		if(x[i].size() == 0) continue;
		int where = lower_bound(x[i].begin(),x[i].end(),pre)-x[i].begin();
		if(where == x[i].size()) where = 0;
		for(int j = 0;j<x[i].size();j++){
			ans+=calc(pre,x[i][where]);
			add(x[i][where],-1);
			pre = x[i][where];
			where = (where+1)%(int)(x[i].size());
		} 
	}
	printf("%I64d\n",ans);
	return 0;
}
