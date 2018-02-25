#include<iostream>
using namespace std;


/*
// ���Ż�·�� 
int find(int x){
	return fa[x] == x? x:find(fa[x])
}
//�Ż�·��
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
			id = new T[sz];//�����int ����hash 
			sz = new int[sz](1);
			for(int i = 0;i<sz;i++) *(id+i) = i;
			count = sz;
			init_size = sz;
			//for(int i = 0;i<sz;i++) sz[i] = 1;
		}
		int count(){return count;}
		int find(int p)
		{
			//������һ��ÿ���ڵ�ĸ��ڵ�ָ��ľ���������һ��
			//���Ϻ�����𽥵���ӽڵ�������ָ����ڵ�
			//���ͷǳ���ƽ �ǳ��� 
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
				id[qroot] = proot;//��Ȼsize�����Ϊ����Ҫ����
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
		T* id;//��ͨ����� 
		int count;
		int init_size;
		int* size;//���Ǹ��ڵ��size��û������ 
}; 
int main()
{
	
 } 
