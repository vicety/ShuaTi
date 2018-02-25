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
};//因为要根据 v 是否为 0 判断 dis 所以 v 一般情况下不能为零 
class Leftist_Tree
{
	public:
		Leftist_Tree(int size)
		{
			heap = new Tree[size+1]; //注意下标 
			for(int i = 1;i<=size;i++)
			{
				heap[i].f = i;
				heap[i].l = heap[i].r = heap[i].dis = 0;
			} 
		}
		int merge(int a,int b)// a 和 b 为两个要合并的树的根节点 
		{
			if(a == 0) return b;
			if(b == 0) return a;
			if(heap[a].v<heap[b].v) swap(a,b); //确保 a 是根节点 v 大的 通过修改大小于号
			//	达到堆的根节点为最大值或最小值的目的 
			heap[a].r = merge(heap[a].r,b); //a 的右子树与 b 合并后成为 a 的新右子树
			heap[heap[a].r].f = a; //双向连接 
			if(heap[heap[a].l].dis < heap[heap[a].r].dis) swap(heap[a].l,heap[a].r);
			// 确保左子树dis更大
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
//这里每个节点的father并不是必要的 ， 这里为了通过并查集找祖先获得最大值设置father 
//这里就不好用并查集模板…… 绝望 
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
		findx = tree.merge(ffx,findx);   //这里fx fy 只是用于暂存 变量名已经失去意义 
		findy = tree.merge(ffy,findy);
		printf("%d\n",tree.heap[tree.merge(findx,findy)].v);
	}
	}
	return 0;
}
