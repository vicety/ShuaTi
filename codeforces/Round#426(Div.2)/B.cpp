#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int>vst;
vector<int>ved;
int vis[26];
int n,k,pst,ped,now,maxx;
char str[1000010];
int arr[1000010];
int st[26];
int en[26];
int main(){
	int cnt = 0;
	scanf("%d%d",&n,&k);
	scanf(" %s",str);
	for(int i = 0;i<n;i++){
		arr[i] = (int)(str[i]-'A');
	}
	for(int i = 0;i<n;i++){
		if(!vis[arr[i]]){
			vst.push_back(i);
			vis[arr[i]] = true;
			cnt++;
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i = n-1;i>=0;i--){
		if(!vis[arr[i]]){
			ved.push_back(i);
			vis[arr[i]] = true;
		}
	}
	//cout<<"here\n";
	sort(vst.begin(),vst.end());
	sort(ved.begin(),ved.end());
	//for(int i = 0;i<cnt;i++) cout<<"......"<<vst[i]<<" "<<ved[i]<<endl;
	//cout<<"here\n";
	while(pst<cnt&&ped<cnt){
		//cout<<pst<<" "<<ped<<endl;
		if(pst == cnt){
			break;
		}
		if(vst[pst]<ved[ped]){
			now++;
			pst++;
			maxx = max(maxx,now);
		}
		else if(vst[pst] == ved[ped]){
			maxx = max(maxx,now+1);
			pst++,ped++;
		}
		else if(vst[pst]>ved[ped]){
			ped++;
			now--;
		}
	}
	//cout<<maxx<<endl;
	maxx>k?(cout<<"YES"):(cout<<"NO");
	return 0;
}
