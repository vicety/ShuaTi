#include<iostream>
using namespace std;


/*
// 不优化路径 
int find(int x){
	return fa[x] == x? x:find(fa[x])
}
//优化路径
int find(int x){
	return fa[x] == x? x:fa[x] = find(fa[x])
}
*/


template<class T>
class<T> UF
{
	public:
		UF(int sz)
		{
			id = new T[sz];//如果非int 进行hash 
			sz = new int[sz](1);
			for(int i = 0;i<sz;i++) *(id+i) = i;
			count = sz;
			init_size = sz;
			//for(int i = 0;i<sz;i++) sz[i] = 1;
		}
		int count(){return count;}
		int find(int p)
		{
			//不加这一行每个节点的父节点指向的就是树的上一级
			//加上后会在逐渐的添加节点中最终指向根节点
			//树就非常扁平 非常优 
			while(p!=id[p]{p = id[p]}return p;
		}
		bool connected(int p,int q){return id[p] == id[q];}
		void union(int p,int q)
		{
			int proot = find(p);
			int qroot = find(q);
			if(proot == qroot) return;
			if(sz[proot]>sz[qroot])
			{
				id[qroot] = proot;//显然size大的作为树根要更快
				sz[proot] += sz[qroot];
			}
			else
			{
				id[proot] = qroot;
				sz[qroot] += sz[proot];
			}
			count--;
		}
	private:
		T* id;//联通组序号 
		int count;
		int init_size;
		int* size;//不是根节点的size就没有意义 
}; 
int main()
{
	
 } 
