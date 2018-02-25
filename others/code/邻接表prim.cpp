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
//int g[7][7];
int v;
int vis[7][7] = { 0 };
vector<int>vnew;
bool invnew(int n)
{
	for(int i = 0;i<vnew.size();i++)
	{
		if(vnew[i] == n) return true;
	}
	return false;
}
vector<pair<int, int> >ans;
bool cmp(EDGE a, EDGE b)
{
	return a.value<b.value;
}
int main()
{
	for (int i = 0;i<7;i++)for (int j = 0;j<7;j++)
	{
		g[i][j].from = i;
		g2[i * 7 + j].from = i;
		g[i][j].to = j;
		g2[i * 7 + j].to = j;
	}
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
	cout << g2[0].from << g2[0].to;
	vnew.push_back(0);
	while (vnew.size() != 7)
	{
		cout << "here " << vnew.size() << endl;
		int nowfrom,nowto, index, minv;

		minv = 0x3fffffff;
		for(int i = 0;i<49;i++)
		{
			if(!vis[g2[i].from][g2[i].to]&&(invnew(g2[i].from)&&!invnew(g2[i].to)))
			{
				vis[g2[i].from][g2[i].to] = 1;
				nowfrom = g2[i].from;
				nowto = g2[i].to;
				ans.push_back(make_pair(g2[i].from,g2[i].to));
				break;
			}
		}
		vnew.push_back(nowto);
		
		/*for(int i = 0;i<7;i++)
		{
		if(g[now][i].value<minv&&!vis[i])
		{
		minv = g[now][i].value;
		index = i;
		cout<<minv<<endl;
		}
		}
		ans.push_back(make_pair(now,index));
		cout<<"index "<<index<<endl;
		vnew.push_back(index);*/
	}
	for (int i = 0;i<ans.size();i++)
	{
		//cout << ans[i].first.from << " " << ans[i].second.to << endl;
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}
