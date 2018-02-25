#include<bits/stdc++.h>
using namespace std;
int n,m,k,d,f,t,c;
typedef long long ll;
const ll inf = 1e12;
const int maxn = 1e6+20;
ll l[maxn], r[maxn], minn[maxn];
vector< pair<int, int> >to[maxn], back[maxn];
int main(){
	scanf("%d %d %d",&n, &m, &k);
	for(int i = 0;i<m;i++){
		scanf("%d %d %d %d",&d, &f,&t, &c);
		if(t == 0) to[d].push_back({f,c});
		else back[d].push_back({t,c});
	}
	ll best = inf*n;
	for(int i = 1;i<maxn;i++) minn[i] = inf;
	for(int i = 1;i<maxn;i++){
		for(pair<int,int> p : to[i]){
			int dest = p.first, cost = p.second;
			if(cost<minn[dest]) best-= (minn[dest]-cost), minn[dest] = cost;
		}
		l[i] = best;
	}
	best = inf*n;
	for(int i = 0;i<maxn;i++) minn[i] = inf;
	for(int i = maxn-1;i>=1;i--){
		for(pair<int,int> p : back[i]){
			int dest = p.first, cost = p.second;
			if(cost<minn[dest]) best-=(minn[dest]-cost), minn[dest] = cost;
		}
		r[i] = best;
	}
	ll ans = inf*n;
	for(int i = 1;i<maxn-k-1;i++){
		int rr = i+k+1;
		ans = min(ans,l[i]+r[rr]);
	}
	if(ans>=inf) return 0*printf("-1");
	return 0*printf("%I64d",ans);
}