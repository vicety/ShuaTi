#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
const int maxn = 65535;
inline int read(){
	int x = 0,f= 1; char ch = getchar();
	while(ch<'0' || ch>'9') {if(ch == '-') f=-1;ch = getchar();}
	while(ch>='0'&& ch<='9') {x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
int cas,n,a,b;
char str[10];
struct NODE{
	int l,r,x;
}node[(maxn<<2)+10];
void build(int rt,int l,int r){
	if((node[rt].l = l) == (node[rt].r = r)) return ;
	int mid = node[rt].l+node[rt].r>>1;
	build(rt<<1,l,mid); build(rt<<1|1,mid+1,r);
}
void insert(int rt,int val,int ind){
	if(node[rt].l == node[rt].r){
		//cout<<node[rt].l<<" "<<val<<" "<<node[rt].x<<endl;
		node[rt].x += val;
		return;
	}
	int mid = node[rt].l+node[rt].r>>1;
	insert(rt<<1|ind>mid,val,ind);
	node[rt].x = node[rt<<1].x+node[rt<<1|1].x;
}
int query(int rt,int l,int r){
	//cout<<"rt l r: "<<rt<<" "<<node[rt].l<<" "<<node[rt].r<<" "<<l<<" "<<r<<endl;
	int ans = 0;
	if(node[rt].l >= l && node[rt].r <= r){
		//cout<<"add "<<node[rt].x<<endl;
		return node[rt].x;
	}
	int mid = node[rt].l+node[rt].r>>1;
	if(l>mid) return query(rt<<1|1,l,r);
	if(r<=mid) return query(rt<<1,l,r);
	return query(rt<<1,l,r)+query(rt<<1|1,l,r);
}
void init(){
	memset(node,0,sizeof(node));
}
int main(){
	cas = read();
	for(int j = 1;j<=cas;j++){
		printf("Case %d:\n",j);
		n = read();
		init();
		build(1,0,65535);
		for(int i = 0;i<n;i++) insert(1,read(),i);
		while(scanf("%s",str) && str[0] !='E'){
			scanf("%d%d",&a,&b);
			if(str[0] == 'Q') printf("%d\n",query(1,a-1,b-1));
			else if(str[0] == 'A') insert(1,b,a-1);
			else if(str[0] == 'S') insert(1,-b,a-1);
			
		}
	}
	return 0;
}
//C:\Users\HCY>scrapy shell blog.jobbole.com/all-posts/
