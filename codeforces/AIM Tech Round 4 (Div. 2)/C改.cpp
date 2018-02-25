#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int vis[100100];
int ffind[100100],n,tmp,cur,gcnt,head;
int ori[100100],ano[100100];
vector<int>group[100100];
int main(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d",&ori[i]);
		ano[i] = ori[i];
	}
	sort(ano+1,ano+n+1);
	for(int i = 1;i<=n;i++) mp[ano[i]+1e9+10] = i;
	for(int i = 1;i<=n;i++) ori[i] = mp[ori[i]],ano[i] = ori[i],ffind[ori[i]] = i;;
	sort(ano+1,ano+n+1);
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
			vis[i] = 1;
			cur = i;
			if(ori[cur] == ano[cur]){
				group[++gcnt].push_back(i);
			}
			else{
				head = ori[i];
				group[++gcnt].push_back(i);
				while(ano[cur] != head){
					cur = ffind[ano[cur]];
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
