#include<iostream>
using namespace std;
template<class T>
class UF
{
	public:
		UF(int sz)
		{
			id = new T[sz];//�����int ����hash 
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
			//������һ��ÿ���ڵ�ĸ��ڵ�ָ��ľ���������һ��
			//���Ϻ�����𽥵���ӽڵ�������ָ����ڵ�
			//���ͷǳ���ƽ �ǳ��� 
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
				id[qroot] = proot;//��Ȼsize�����Ϊ����Ҫ����
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
		T* id;//��ͨ����� 
		int cnt;
		int init_size;
		int* size;//���Ǹ��ڵ��size��û������ 
}; 
int main()
{
	UF<int> uf(2);
 } 
