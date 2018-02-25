#include<bits/stdc++.h>//706D
using namespace std;
const int maxn = 2e5 + 20;//��̫��⡭�� 
/*
������ڵ�һ���ַ������������ָ�����һ��Ĳ�ţ���������ڣ���size��ֵΪ��һ��Ĳ�ţ�size++ 
*/
struct Trie
{
	int ch[maxn<<5][2],val[maxn<<5],sz = 0;
	void inin(){
		sz = 1;//memset(ch[0],0,sizeof(ch[0]));//sizeȡ0û������ 
	//	memset(ch,0,sizeof(ch));memset(val,0,sizeof(val));
	}
	void insert(int x,int v)
	{
		int u = 0;
		for(int i = 30 ; i >=0 ; i--)
		{
			int c = (x>>i) &1;//c��Ҫ�������Ķ����Ƶ�i+1λ 
			if(!ch[u][c])//�����δ¼���ֵ����ĵ�u�㣬�Ե�ǰ���ڵ���߲�+1��ʼ��Ϊ0 
			{
				//memset(ch[sz],0,sizeof(ch[sz]));//��ʼ����һ�� 
				val[sz] = 0;//���val 
				ch[u][c] = sz++;//��ch[��][��i+1λ]��ֵΪ���������������������š��� 
			}
			u = ch[u][c];//�����һ��Ĳ��   ������� 
			val[u] += v;//������һ���ڵ�Ĵ����ӵ���v 
		}
	}
	int query(int x)
	{
		int ans = 0,u = 0;
		for(int i = 30 ; i >= 0; i --)
		{
			int id = (x >> i) & 1;  //��Ȩֵ�ߵĴ�λ��ʼ 
			if(!ch[u][id^1] || !val[ch[u][id^1]])//�����һ����֧����һ�㲻���ڻ���val[��һ����֧����һ��]Ϊ0 
				u = ch[u][id];//��һ��ָ��Ҫ��ѯ��������һλ����һ�� 
			else//�����������һλ������һλ��val = 0(Ҳ����˵��erase��) 
			{
				u = ch[u][id^1];
				ans |= 1<<i;//ȡ����һλ������ 
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
