#include<bits/stdc++.h>
using namespace std;
int n, k;
struct EVE{
	int st,ed,val;
	EVE(){
	}
	EVE(int a,int b, int c){
		st = a, ed = b, val = c;
	}
};
int f,t,c;
vector<EVE> v[200200];
vector<int> minn[200200];
int tmp[200200];
bool cmp(EVE a, EVE b){
	return a.st<b.st;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i = 0;i<n;i++){
		scanf("%d%d%d",&f,&t,&c);
		if(t-f+1 >= k) continue;
		v[t-f+1].push_back({f,t,c});
	}
	for(int i = 1;i<=k;i++) sort(v[i].begin(),v[i].end(),cmp);
	for(int i = 1;i<=k;i++){
		for(int j = v[i].size()-1;j>=0;j--){
			if(j==v[i].size()-1) tmp[j]=v[i][j].val;
            else tmp[j]=min(v[i][j].val,tmp[j+1]);
		}
		for(int j = 0;j<v[i].size();j++){
			minn[i].push_back(tmp[j]);
		}
	}
	long long ans = 1e12;
	for(int i = 1;i<=k;i++){
		if(v[k-i].empty()) continue;
		for(int j = 0;j<v[i].size();j++){
			int ed = v[i][j].ed;
			long long cost = v[i][j].val;
			int le = 0, ri = v[k-i].size()-1;
			if(v[k-i][ri].st<=ed) continue;
			int mid = le+ri>>1;
			while(le<ri){
				mid = le+ri>>1;
				if(v[k-i][mid].st<=ed) le = mid+1;
				else ri = mid;
			}
			//le = upper_bound(v[k-i].begin(),v[k-i].end(),EVE(ed,0,0), cmp)-v[k-i].begin();
			//cout<<i<<" "<<le<<endl;
			ans = min(ans, cost+minn[k-i][le]);
		}
	}
	if(ans == 1e12) printf("-1");
	else printf("%I64d",ans);
	return 0;
} 