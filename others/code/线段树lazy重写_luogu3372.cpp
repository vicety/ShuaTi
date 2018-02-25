#include<bits/stdc++.h>
using namespace std;
inline long long read() {
	long long x = 0, f = 1; char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') f = -1;ch = getchar(); }
	while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0';ch = getchar(); }
	return x*f;
}
const int maxn = 131071;
int n,m,op,_l,_r,k;
struct NODE{
	int l,r;
	long long lazy,val;
}node[maxn<<2];
void pushup(int rt){
	node[rt].val = node[rt<<1].val+node[rt<<1|1].val;
}
void pushdown(int rt){
	if(!node[rt].lazy) return ;
	int mid = node[rt].l+node[rt].r >>1;
	node[rt<<1].lazy += node[rt].lazy;
	node[rt<<1|1].lazy += node[rt].lazy;
	node[rt<<1].val += node[rt].lazy*(mid-node[rt].l+1);
	node[rt<<1|1].val += node[rt].lazy*(node[rt].r-mid);
	node[rt].lazy = 0;
	
}
void build(int x,int l,int r){
	if((node[x].l = l) == (node[x].r = r)) return;
	int mid = node[x].l+node[x].r>>1;
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
}
//单点更新 
void add_one(int rt,int pos,long long val){ 
	if(node[rt].l == node[rt].r){
		node[rt].val+=val;
		return;
	}
	int mid = node[rt].l+node[rt].r>>1;
	add_one(rt<<1|pos>mid,pos,val);
	pushup(rt);
}
//区域更新 
//所谓lazy就是只有当需要pushdown时才pushdown，query同 
void add(int rt,int l,int r,int val){ 
	pushdown(rt); // 这一行的作用见 https://jecvay.com/2014/11/segment-tree-lazy-design.html 
	if(node[rt].l>=l && node[rt].r<=r){  
		node[rt].val+=val*(node[rt].r-node[rt].l+1);
		node[rt].lazy += val;
		return ;
	}
	int mid = node[rt].l+node[rt].r>>1;
	if(l<=mid) add(rt<<1,l,r,val);
	if(r>mid) add(rt<<1|1,l,r,val);
	pushup(rt);
}
long long query(int rt,int l,int r){
	pushdown(rt); 
	if(node[rt].l>=l && node[rt].r<=r) return node[rt].val;
	int mid = node[rt].l + node[rt].r >> 1;
	long long ans = 0;
	if(l<=mid) ans+=query(rt<<1,l,r); // 易错 
	if(r>mid) ans+=query(rt<<1|1,l,r);
	return ans;
}
int main(){
	n = read(), m = read();
	build(1,0,n);
	for(int i = 0;i<n;i++) add_one(1,i,read());
	for(int i = 0;i<m;i++){
		op = read();_l = read()-1; _r = read()-1;
		if(op-1) printf("%lld\n",query(1,_l,_r));
		else{
			k = read();
			add(1,_l,_r,k);
		}
	}
	return 0;
}
