#include<iostream>
using namespace std;
template<class T>
class UF
{
	public:
		UF(int sz)
		{
			id = new T[sz];//如果非int 进行hash 
			size = new int[sz];
			for(int i = 0;i<sz;i++) *(id+i) = i;
			cnt = sz;
			init_size = sz;
			for(int i = 0;i<sz;i++) size[i] = 1;
		}
		int count(){return count;}
		int find(int p)
		{
			id[p] = id[id[p]];
			//不加这一行每个节点的父节点指向的就是树的上一级
			//加上后会在逐渐的添加节点中最终指向根节点
			//树就非常扁平 非常优 
			while(p!=id[p]){p = id[p];}
			return p;
		}
		bool connected(int p,int q){return id[p] == id[q];}
		void unite(int p,int q)
		{
			int proot = find(p);
			int qroot = find(q);
			if(proot == qroot) return;
			if(size[proot]>size[qroot])
			{
				id[qroot] = proot;//显然size大的作为树根要更快
				size[proot] += size[qroot];
			}
			else
			{
				id[proot] = qroot;
				size[qroot] += size[proot];
			}
			cnt--;
		}
	private:
		T* id;//联通组序号 
		int cnt;
		int init_size;
		int* size;//不是根节点的size就没有意义 
}; 
int main()
{
	UF<int> uf(2);
 } 
