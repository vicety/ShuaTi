#include<bits/stdc++.h>
using namespace std;
const int maxn = 300300;
int num[300300][20];
int arr[30];
int n,q,u,v,sum,tt,tmp,m;
void init()
{
	memset(num,0,sizeof(num));
	for(int i = 0;i<n;i++){
		scanf("%d",&tmp);
		num[tmp][0]++;
	}
	for(int i = 1;(1<<i)<=maxn;i++)
	{
		for(int j = 1;j+(1<<i)-1<=maxn;j++)
		{
			num[j][i] = num[j][i-1] + num[j+(1<<(i-1))][i-1];
		}
	} 
}
int query()
{
//	double temp = r-l+1;
//	if(temp == 1.0) return l;
//	int range = (int)(log(temp)/log(2.0));
//	return max(cmax[l][range],cmax[r-(1<<range)+1][range])-min(cmin[l][range],cmin[r-(1<<range)+1][range]);
	sum = 0;
	for(int i = 18;i>=0;i++){
		if(arr[i] && num[sum][i]) sum+=(1<<i);
		if(!arr[i] && !num[sum][i]) sum+=(1<<i);
	}
	return sum;
}
int main(){
	scanf("%d%d",&n,&m);
	init();
	cout<<"here\n";
	while(m--){
		scanf("%d",&tt);
		memset(arr,0,sizeof(arr));
		q^=tt;
		for(int i = 0;i<20;i++){
			if(q&1) arr[19-i]++;
			q>>=1;
		}
		for(int i = 0;i<20;i++) cout<<arr[i];
		cout<<endl;
		printf("%d\n",query());
	}
	return 0;
} 
