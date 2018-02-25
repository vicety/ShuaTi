#include<bits/stdc++.h>
using namespace std;
int n,st,x;
int arr[50010];
int vis[50010],next,flag,prev,lleft,pcur;
int cur = -0x3f3f3f3f;
int main(){
	cin>>n>>st>>x;
	cout<<"? "<<st<<endl;
	fflush(stdout);
	cin>>cur>>next;
	if(cur>=x){
		cout<<cur<<endl;
		return 0;
	}
	pcur = st;
	lleft = 1998;
	while(1){
		if(!lleft) exit(0);
		if(cur<x && x-cur<=lleft){
			flag = 0;
			while(!flag){
				//cout<<"here\n";
				prev = cur;
				cout<<"? "<<next<<endl;
				fflush(stdout);
				cin>>cur>>next;
				if(cur>=x) flag = 1;
					//cout<<"! "<<cur<<endl;
			}
			cout<<"! "<<cur<<endl;
			return 0;
		}
		else{
			vis[pcur] = 1;
			if(cur == x){
				cout<<"! "<<cur<<endl;
				return 0;
			}
			for(int i = 0;i<n;i++){
				if(!vis[i]){
					pcur = next;
					cout<<"? "<<i<<endl;
					fflush(stdout);
					cin>>cur>>next;
					if(next == -1){
						//vis[pcur] = 1;
						if(cur<x){
							cout<<"! -1"<<endl;
							return 0;
						}
						//continue;
					}
					lleft--;
					break;
				}
			}
		}
	}
	return 0;
}
