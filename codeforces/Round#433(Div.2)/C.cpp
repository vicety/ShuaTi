#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x = 0,f= 1; char ch = getchar();
	while(ch<'0' || ch>'9') {if(ch == '-') f=-1;ch = getchar();}
	while(ch>='0'&&ch<='9') {x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
int n, k;
long long ans;
struct F{
	long long t;
	long long v;
	int ans;
	F(){}
	F(int a,int b){
		t = a, v = b;
	}
}f[300100];
struct CMPT{
	bool operator()(const F& a, const F& b){
		return a.t>b.t;
	}
};
struct CMPV{
	bool operator()(const F& a, const F& b){
		return a.v<b.v;
	}
};
priority_queue<F, vector<F>, CMPT> qt;
priority_queue<F, vector<F>, CMPV> qv;
int main(){
	scanf("%d%d",&n,&k);
	for(int i = 1;i<=n;i++) f[i] = F(i, read()), qt.push(f[i]);
	while(qt.top().t<=k && !qt.empty()){
		qv.push(qt.top());
		qt.pop();
	} 
	for(int i = k+1;i<=k+n;i++){
		if(!qt.empty()) qv.push(qt.top()), qt.pop();
		ans += (i-qv.top().t)*qv.top().v, f[qv.top().t].ans = i;
		qv.pop();
	}
	printf("%I64d\n",ans);
	for(int i = 1;i<=n;i++) printf("%d%s",f[i].ans,(i == n?"\n":" "));
	return 0;
}