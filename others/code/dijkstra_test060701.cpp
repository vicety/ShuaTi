#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<Windows.h>
#include<cstring>
#include<set>
#include<sstream>
using namespace std;
const int inf = 0x3fffffff;
//vector<pair<int, int> >graph;
//graph.pushback(make_pair(4,5))
int mp[12][12];
int vis[12];
int dis[12];
string path[12];
stringstream ss;
string temp;
char c_temp[256];
int temp_len, temp_index;
set<int> uni[12];
set<int>::iterator it;
queue<int>q;
int main()
{
	int count = 0;
	path[1] = "1";
	//memset(mp, inf, sizeof(mp));
	for (int i = 1;i <= 11;i++)
	{
		for (int j = 1;j <= 11;j++)
		{
			mp[i][j] = inf;
		}
	}
	for (int i = 2;i <= 11;i++)
	{
		dis[i] = inf;
	}
	memset(vis, 0, sizeof(vis));
	//cout << mp[2][3] << endl;
	dis[0] = 0;
	freopen("C:/Users/HCY/Desktop/input.txt", "r", stdin);
	int st, ed, len;
	while (cin >> st && st)
	{
		cin >> ed >> len;
		mp[st][ed] = len;
		mp[ed][st] = len;
	}
	for (int i = 1;i <= 11;i++)
	{
		for (int j = 1;j <= 11;j++)
		{
			if (mp[i][j] != inf)
			{
				uni[i].insert(j);
				uni[j].insert(i);
			}
		}
	}
	while (count <= 11)
	{
		temp_len = inf;
		for (int i = 1;i <= 11;i++)
		{
			if (!vis[i] && dis[i] < temp_len)
			{
				temp_index = i;
				temp_len = dis[i];
			}
		}
		vis[temp_index] = 1;
		count++;
		for (it = uni[temp_index].begin();it!= uni[temp_index].end();it++)
		{
			if (dis[temp_index] + mp[temp_index][*it] < dis[*it])
			{
				//cout<<*it<<endl;
				dis[*it] = dis[temp_index] + mp[temp_index][*it];
				//ss<<*it;
				//ss>>temp;
				sprintf(c_temp,"%d",*it);
				temp = c_temp;
				//ss.str("");
				//cout<<"temp: "<<temp<<endl;
				path[*it] = path[temp_index]+" -> "+temp;
			} 
		}
	}

	/*for (int i = 1;i <= 11;i++)
	{
	temp_len = inf;
	for (int j = 1;j <= 11;j++)
	{
	if (j == i || mp[i][j] == inf || vis[j]) continue;
	if (dis[i] + mp[i][j] < dis[j]) dis[j] = dis[i] + mp[i][j];
	if (mp[i][j] < temp_len)
	{
	temp_len = mp[i][j];
	temp_index = j;
	}
	}
	temp_
	}*/
	for (int i = 2;i <= 11;i++)
	{
		cout <<"index: "<<i<<endl<<" dis: "<< dis[i] <<endl<< " path: " << path[i] << endl<<endl ;
	} 
	Sleep(100000000);
	return 0;
}
