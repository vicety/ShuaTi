#include<bits/stdc++.h>
using namespace std;
inline long long read() {
	long long x = 0, f = 1; char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-') f = -1;ch = getchar(); }
	while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0';ch = getchar(); }
	return x*f;
}
int mp[15][15];
int line[15];
int row[15],tt;
int ys[30];
int yx[30];
int n,cnt,back;
//vector<int> v[3];
bool uncollapse(int x,int y){
	if(row[y] || line[x]) return false;
	if(ys[x+y] || yx[x-y+15] ) return false;
	return true;
}
void dfs(int l,vector<int>v){
	for(int j = 1;j<=n;j++){
		/*if(back){
			back--;
			return;
		}*/
		//if(l == 1 && j!=tt) continue;
		if(uncollapse(j,l)){
			v.push_back(j);
			if(l != n){
				line[j] = 1;
				row[l] = 1;
				ys[j+l] = 1;
				yx[j-l+15] = 1;
				dfs(l+1,v);
				v.pop_back();
				line[j] = 0;
				row[l] = 0;
				ys[j+l] = 0;
				yx[j-l+15] = 0;
			}
			else{
				if(cnt<3){
					for(int i = 0;i<v.size();i++) printf("%d ",v[i]);
					printf("\n");
				}
				cnt++;
			}	
		}
	}
}
int main(){
	n = read();
	vector<int>v;
	dfs(1,v);
	printf("%d\n",cnt);
	return 0;
} 
