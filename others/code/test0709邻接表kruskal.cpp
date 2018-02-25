#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
/*
0 7 0 5 0 0 0
7 0 8 9 7 0 0
0 8 0 0 5 0 0
5 9 0 0 15 6 0
0 7 5 15 0 8 9
0 0 0 6 8 0 11
0 0 0 0 9 11 0
http://www.cnblogs.com/biyeymyhjob/archive/2012/07/30/2615542.html
*/
using namespace std;
struct EDGE
{
	int from;
	int to;
	int value;
}g[7][7];
EDGE g2[49];
vector<pair<int,int> >ans;
int f[7];
int v;
bool cmp(EDGE a, EDGE b)
{
	return a.value<b.value;
}
int find(int x)
{
	return f[x] == x?x:find(f[x]);
}
void merge(int a,int b)
{
	int fa = find(a),fb = find(b);
	if(fa == fb) return;
	else
	{
		f[fa] = fb;//本来写的是f[fa] = fb 这样就路径压缩了，这里不能压 
	}
}
int main()
{
	int line = 0;
	for (int i = 0;i<7;i++)for (int j = 0;j<7;j++)
	{
		g[i][j].from = i;
		g2[i * 7 + j].from = i;
		g[i][j].to = j;
		g2[i * 7 + j].to = j;
	}
	for(int i = 0;i<7;i++)f[i] = i;
	freopen("C:/Users/HCY/Desktop/input.txt", "r", stdin);
	for (int i = 0;i<7;i++)
	{
		for (int j = 0;j<7;j++)
		{
			cin >> v;
			if (v)
			{
				g[i][j].value = v;
				g2[i*7+j].value = v;
			}
			else
			{
				g[i][j].value = 0x3fffffff;
				g2[i * 7 + j].value = 0x3fffffff;
			}
			/*if(!v)
			{
			g[i].push_back(j);
			g[j].push_back(i);
			}*/
		}
	}
	sort(g2, g2 + 49, cmp);
	for(int i = 0;i<49;i++)
	{
		cout<<"here "<<g2[i].from<<" "<<g2[i].to<<endl;;
		cout<<"here "<<find(g2[i].from)<<" "<<find(g2[i].to)<<endl; 
		if(line == 6)break;
		if(!(find(g2[i].from) == find(g2[i].to)))
		{
			ans.push_back(make_pair(g2[i].from,g2[i].to));
			merge(g2[i].from,g2[i].to);
			line++;
			cout<<"line "<<line<<endl;
		}
		//for(int i = 0;i<7;i++)cout<<f[i]<<endl;
		cout<<"end"<<endl;
	}
	for(int i = 0;i<ans.size();i++)cout<<ans[i].first<<" "<<ans[i].second<<endl;
	return 0;
}
