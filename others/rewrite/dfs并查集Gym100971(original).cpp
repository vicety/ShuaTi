//—≈π€“ªÕÚ±∂°£°£°£ 
#include<bits/stdc++.h>
#include<queue> 
using namespace std;
int row,line;
char mapp[50][50];
bool visit[50][50];
char temp_c;
queue<pair<int,int> > q;
pair<int,int> temp_p;
int k;
int all_block;
int block;
void reset()
{
	for(int i = 0;i<row;i++)
		{
			for(int j = 0;j<line;j++)
			{
				if(mapp[i][j] == '.'||mapp[i][j] == '?') visit[i][j] = false;
			}
		}
}
void bfs_judge()
{
	k = 0;
	block = 0;
	for(int i = 0;i<row;i++)
	{
		for(int j = 0;j<line;j++)
		{
			if(mapp[i][j] == '.'&&!visit[i][j])
			{
				//cout<<i<<" "<<j<<endl;
				q.push(make_pair(i,j));
				block++;
				visit[i][j] = true;
				k++;
				//if(k>1) return;
				while(!q.empty())
				{
					temp_p = q.front();
					int x = temp_p.first;
					int y = temp_p.second;
					//cout<<"in queue "<<x<<" "<<y<<endl;
					//visit[x][y] = true;
					q.pop();
					if(!visit[x-1][y]&&x-1>=0)
					{
						q.push(make_pair(x-1,y));
						visit[x-1][y] = true;
						block++;
					} 
					if(!visit[x+1][y]&&x+1<row)
					{
						q.push(make_pair(x+1,y));
						visit[x+1][y] = true;
						block++;
					 } 
					if(!visit[x][y-1]&&y-1>=0)
					{
						q.push(make_pair(x,y-1));
						visit[x][y-1] = true;
						block++;
					 }
					if(!visit[x][y+1]&&y+1<line)
					{
						q.push(make_pair(x,y+1));
						visit[x][y+1] = true;
						block++;
					 }
					//cout<<q.size()<<endl;
				}				
			}
		}
	}
	//cout<<"block "<<block<<endl;
}
int main()
{
	//freopen("C:/Users/HCY/Desktop/input2.txt","r",stdin);
	cin>>row>>line;
	for(int i = 0;i<row;i++)
	{
		for(int j = 0;j<line;j++)
		{
			cin>>temp_c;
			mapp[i][j]= temp_c;
			if(temp_c == '#') visit[i][j] = true;
			if(temp_c == '.'||temp_c == '?') visit[i][j] = false;
		}
	}
	//cout<<"input complete\n";
	bfs_judge();
	all_block = block;
	//cout<<all_block<<endl;
	//cout<<"judge complete\n";
	if(k>1) cout<<"Impossible";
	else
	{
		reset();
		for(int i = 0;i<row;i++)
		{
			for(int j = 0;j<line;j++)
			{
				if(mapp[i][j] == '?')
				{
					//cout<<"here";
					reset();
					visit[i][j] = true;
					//cout<<i<<" here "<<j<<endl;
					bfs_judge();
					if(block == all_block-1&&k == 1)
					{
						cout<<"Ambiguous";
						return 0;
					}
					else if(block == all_block&&k == 1)
					{
						mapp[i][j] = '#';
					}
					else
					{
						mapp[i][j] = '.';
						//cout<<"here";
					}
					//cout<<block<<endl;
					visit[i][j] = false;
				}
			}
		}
		bfs_judge();
		for(int i = 0;i<row;i++)
		{
			for(int j = 0;j<line;j++)
			{
				cout<<mapp[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
} 
