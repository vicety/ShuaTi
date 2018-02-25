#include<bits/stdc++.h>
using namespace std;
int a[200100];
struct B{
	int num;
	int ind;
	int to;
}b[200100];
bool cmp(B a,B b){
	return a.num<b.num;
}
bool cmp_2(B a,B b){
	return a.ind<b.ind;
}
int m;

int main(){
	cin>>m;
	for(int i = 0;i<m;i++) scanf("%d",&a[i]);
	for(int i = 0;i<m;i++) scanf("%d",&b[i].num),b[i].ind = i;;
	sort(a,a+m);
	sort(b,b+m,cmp);
	for(int i = 0;i<m;i++){
		b[i].to = a[m-i-1];
	}
	sort(b,b+m,cmp_2);
	for(int i = 0;i<m;i++) printf("%d%s",b[i].to,i == m-1?"":" ");
	return 0;
}

