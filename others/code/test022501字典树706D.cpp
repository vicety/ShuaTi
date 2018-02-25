#include<bits/stdc++.h>//706D
using namespace std;
const int maxn = 2e5 + 20;//不太理解…… 
/*
如果存在第一个字符的树，获得其指向的下一层的层号，如果不存在，将size赋值为下一层的层号，size++ 
*/
struct Trie
{
	int ch[maxn<<5][2],val[maxn<<5],sz = 0;
	void inin(){
		sz = 1;//memset(ch[0],0,sizeof(ch[0]));//size取0没有问题 
	//	memset(ch,0,sizeof(ch));memset(val,0,sizeof(val));
	}
	void insert(int x,int v)
	{
		int u = 0;
		for(int i = 30 ; i >=0 ; i--)
		{
			int c = (x>>i) &1;//c是要插入数的二进制第i+1位 
			if(!ch[u][c])//如果还未录入字典树的第u层，对当前存在的最高层+1初始化为0 
			{
				//memset(ch[sz],0,sizeof(ch[sz]));//初始化下一层 
				val[sz] = 0;//标记val 
				ch[u][c] = sz++;//将ch[层][第i+1位]赋值为层数，但是这个好像是序号…… 
			}
			u = ch[u][c];//获得下一层的层号   如果存在 
			val[u] += v;//经过这一个节点的次数加等于v 
		}
	}
	int query(int x)
	{
		int ans = 0,u = 0;
		for(int i = 30 ; i >= 0; i --)
		{
			int id = (x >> i) & 1;  //从权值高的大位开始 
			if(!ch[u][id^1] || !val[ch[u][id^1]])//如果另一条分支的下一层不存在或者val[另一条分支的下一层]为0 
				u = ch[u][id];//下一层指向要查询的数的这一位的下一层 
			else//如果不存在这一位或者这一位的val = 0(也就是说被erase了) 
			{
				u = ch[u][id^1];
				ans |= 1<<i;//取消这一位的增加 
			}
		}
		return ans;
	}
}tree;
int main(void)
{
	freopen("F://in.txt","r",stdin);
	tree.inin();
	int q,a;
 	char c;
 	cin>>q;
 	tree.insert(0,1);
 	while(q--)
 	{
 		cin>>c>>a;
 		if(c=='+')
 			tree.insert(a,1);
 		else if(c == '-')
 		{
 			tree.insert(a,-1);
		}
		else	cout<<tree.query(a)<<endl;
	}
	fclose(stdin);
	return 0;
} 
/*input 
10
+ 8
+ 9
+ 11
+ 6
+ 1
? 3
- 8
? 3
? 8
? 11 

output
11
10
14
13
*/
