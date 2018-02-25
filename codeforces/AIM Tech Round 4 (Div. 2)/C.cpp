#include<bits/stdc++.h>
using namespace std;
int vis[100100];
int ffind[100100],n,tmp,cur,gcnt,head;
int toseq[100100];
int ori[100100];//ano[100100];
vector<int>group[100100];
struct A{
	int num;
	int seq;
}ano[100100];
bool cmp(A a,A b){
	return a.num<b.num;
}
int main(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d",&ori[i]);
		ano[i].num = ori[i];
		ano[i].seq = i;
		ffind[ori[i]] = i;
	}
	//for(int i = 1;i<=6;i++) cout<<ffind[i]<<" ";
	//cout<<endl;
	sort(ano+1,ano+n+1,cmp);
	for(int i = 1;i<=n;i++){
		toseq[i]
	}
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
			vis[i] = 1;
			cur = i;
			if(ori[cur] == ano[cur]){
				group[++gcnt].push_back(i);
			}
			else{
				head = ori[i];
				//cout<<"head: "<<head<<endl;
				group[++gcnt].push_back(i);
				while(ano[cur] != head){
					cur = ffind[ano[cur]];
					//cout<<i<<" || "<<cur<<endl;
					vis[cur] = 1;
					group[gcnt].push_back(cur);
				}
			}
		}
	}
	printf("%d\n",gcnt);
	for(int i = 1;i<=gcnt;i++){
		printf("%d ",group[i].size());
		for(int j = 0;j<group[i].size();j++){
			printf("%d%s",group[i][j],j == group[i].size()-1?"\n":" ");
		}
	}
	return 0;
}
