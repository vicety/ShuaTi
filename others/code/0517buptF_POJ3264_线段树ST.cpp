//#define ONLINE_JUDGE
//ST 在于不能动态update， 查询(O1) 
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxn = 5e4+20;
int cow[maxn];
int cmax[maxn][18];
int cmin[maxn][18];
int n,q,u,v;
void init(int sz)
{
	for(int i = 1;i<=sz;i++)
	{
		scanf("%d",cow+i);
		cmin[i][0] = cmax[i][0] = cow[i];
	}
	for(int i = 1;(1<<i)<=sz;i++)
	{
		for(int j = 1;j+(1<<i)-1<=sz;j++)
		{
			cmax[j][i] = max(cmax[j][i-1],cmax[j+(1<<(i-1))][i-1]); //从 2^1开始 
			cmin[j][i] = min(cmin[j][i-1],cmin[j+(1<<(i-1))][i-1]);
		}
	} 
}
int query(int l,int r)
{
	double temp = r-l+1;
	int range = (int)(log(temp)/log(2.0));
	return max(cmax[l][range],cmax[r-(1<<range)+1][range])-min(cmin[l][range],cmin[r-(1<<range)+1][range]);
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("C:/Users/HCY/Desktop/input.txt","r",stdin);
	#endif 
	scanf("%d %d",&n,&q);
	init(n);
	while(q--)
	{
		scanf("%d %d",&u,&v);
		printf("%d\n",query(u,v));
	}
	return 0;
}
