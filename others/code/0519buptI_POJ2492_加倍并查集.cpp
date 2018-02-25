#include<iostream>
#include<cstdio> 
using namespace std;
int f[4020];
int size;
int _move;
int u,v;
int found = 0;
void INIT(int size)
{
	found = 0;
	for(int i = 1;i<=2*size;i++) f[i] = i; 
	//for(int i = 1;i<=size;i++) f[i+size] = i;
}
int find(int x)
{
	return f[x] == x?x:f[x]=find(f[x]); 
}
int merge(int a,int b)
{
	int aroot = find(a);
	int broot = find(b);
	f[aroot] = broot;
	return broot;
}
int main()
{
	int cas;
	scanf("%d",&cas);
	for(int i = 1;i<=cas;i++)
	{
		printf("Scenario #%d:\n",i);
		scanf("%d %d",&size,&_move);
		INIT(size);
		for(int j = 1;j<=_move;j++)
		{
			scanf("%d %d",&u,&v);
			merge(u,v+size);
			merge(v,u+size);
		}
		for(int j = 1;j<=size;j++)
		{
			if(f[j] == f[j+size])
			{
				printf("Suspicious bugs found!\n");
				found = 1;
				break;
			} 
		}
		if(!found) printf("No suspicious bugs found!\n");
		printf("\n");
	}
	return 0;
} 
