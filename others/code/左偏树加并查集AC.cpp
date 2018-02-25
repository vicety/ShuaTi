// HDU 1512 
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
/*void swap(int &a,int &b)
{
	int * temp;
	temp = &a;
	&a = &b;
	&a = temp;
}*/
struct Tree{
	int l,r,v,dis,f;
};//��ΪҪ���� v �Ƿ�Ϊ 0 �ж� dis ���� v һ������²���Ϊ�� 
class Leftist_Tree
{
	public:
		Leftist_Tree(int size)
		{
			heap = new Tree[size+1]; //ע���±� 
			for(int i = 1;i<=size;i++)
			{
				heap[i].f = i;
				heap[i].l = heap[i].r = heap[i].dis = 0;
			} 
		}
		int merge(int a,int b)// a �� b Ϊ����Ҫ�ϲ������ĸ��ڵ� 
		{
			if(a == 0) return b;
			if(b == 0) return a;
			if(heap[a].v<heap[b].v) swap(a,b); //ȷ�� a �Ǹ��ڵ� v ��� ͨ���޸Ĵ�С�ں�
			//	�ﵽ�ѵĸ��ڵ�Ϊ���ֵ����Сֵ��Ŀ�� 
			heap[a].r = merge(heap[a].r,b); //a ���������� b �ϲ����Ϊ a ����������
			heap[heap[a].r].f = a; //˫������ 
			if(heap[heap[a].l].dis < heap[heap[a].r].dis) swap(heap[a].l,heap[a].r);
			// ȷ��������dis����
			if(heap[a].r == 0) heap[a].dis = 0;
			else heap[a].dis = heap[heap[a].r].dis+1;
			return a; 
		}
		int pop(int a)
		{
			int l = heap[a].l;
			int r = heap[a].r;
			heap[l].f = l;
			heap[r].f = r;
			heap[a].r = heap[a].l = heap[a].dis = 0;
			return merge(l,r);
		}
		int find(int x){return x == heap[x].f?x:heap[x].f = find(heap[x].f);} 
		~Leftist_Tree()
		{
			delete []heap;
		}
		/*void swap(int a,int b)
		{
			Tree temp;
			temp.l = heap[a].l; temp.r = heap[a].r; temp.v = heap[a].v; temp.dis = heap[a].dis; temp.f = heap[a].f;
			heap[a].l = heap[b].l; heap[a].r = heap[b].r; heap[a].dis = heap[b].dis; heap[a].f = heap[b].f; heap[a].v = heap[b].v;  
			heap[b].l = temp.l; heap[b].r = temp.r; heap[b].dis = temp.dis; heap[b].f = temp.f; heap[b].v = temp.v;
		}*/
	//private:
		Tree* heap;
		
};
//����ÿ���ڵ��father�����Ǳ�Ҫ�� �� ����Ϊ��ͨ�����鼯�����Ȼ�����ֵ����father 
//����Ͳ����ò��鼯ģ�塭�� ���� 
int main()
{
	freopen("C:/Users/HCY/Desktop/input.txt","r",stdin);
	int size,ope;
	while(~scanf("%d",&size))
	{
	Leftist_Tree tree(size);
	for(int i = 1;i<=size;i++) scanf("%d",&tree.heap[i].v);
	scanf("%d",&ope);
	while(ope--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		
		int findx = tree.find(x);
		
		int findy = tree.find(y);
		if(findx == findy)
		{
			printf("-1\n");
			continue;
		}
		tree.heap[findx].v/=2; tree.heap[findy].v/=2;
		int ffx = tree.pop(findx);
		int ffy = tree.pop(findy);
		findx = tree.merge(ffx,findx);   //����fx fy ֻ�������ݴ� �������Ѿ�ʧȥ���� 
		findy = tree.merge(ffy,findy);
		printf("%d\n",tree.heap[tree.merge(findx,findy)].v);
	}
	}
	return 0;
}
