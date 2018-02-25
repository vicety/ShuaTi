#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
// # 1  ? 2  . 3

/*
5 8
.?.?.?.?
####.###
####?###
####?###
.?.?.?..

*/
int n,m,mp[52][52],blocknum,qnum,emptynum,flag,out;
char tmp;
int size[2550],fa[2550],vis[2550],mark[52][52];
int find(int x){
	return fa[x] == x?x:fa[x] = find(fa[x]);
}
void init(){
	memset(vis,0,sizeof(vis));
	for(int i = 0;i<2550;i++){
		fa[i] = i;
		size[i] = 1;
	} 
}
void merge(int u,int tov){
	int fu = find(u);
	int fv = find(tov);
	if(fu == fv) return;
	fa[fu] = fv;
	size[fv] += size[fu];
	//size[fu] = 0;
}
int get(int i,int j){
	return i*n+j;
}
bool outrange(int i,int j){
	if(i>=n || j>=m) return true;
	if(i<0 || j<0) return true;
	if(mp[i][j] == 1) return true;
	return false;
}
void dfs(int i,int j,int fi,int fj){
	if(outrange(i,j) || vis[get(i,j)]) return;
	//cout<<i<<" "<<j<<endl;
	vis[get(i,j)] = true;
	merge(get(i,j),get(fi,fj));
	dfs(i+1,j,i,j);
	dfs(i-1,j,i,j);
	dfs(i,j+1,i,j);
	dfs(i,j-1,i,j);
}
void dfss(int i,int j){
	if(outrange(i,j) || vis[get(i,j)]) return;
	//cout<<i<<" "<<j<<endl;
	if(mp[i][j] == 2) mark[i][j] = 1;
	vis[get(i,j)] = true;
	//merge(i,j);
	dfss(i+1,j);
	dfss(i-1,j);
	dfss(i,j+1);
	dfss(i,j-1);
}
bool judge_has(){
	init();
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			dfs(i,j,i,j);
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(size[get(i,j)] == qnum+emptynum) return true;
		}
	}
	return false;
}
bool all_dfs(){
	for(int i =0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(mp[i][j] == 2){
				//cout<<"here\n";
				mp[i][j] = 1;
				init();
				for(int k = 0;k<n;k++){
					if(out) break;
					for(int l = 0;l<m;l++){
						if(out) break;
						if(mp[k][l] != 1){
							//cout<<k<<" "<<l<<endl;
							dfs(k,l,k,l);
							out = 1;
						}
					}
				}
				mp[i][j] = 2;
				/*if(i == 0 && j == 7){
					for(int k = 0;k<n;k++){
						for(int l = 0;l<m;l++){
							cout<<size[k*8+l]<<" ";
						}
						cout<<endl;
					}
				}*/
				for(int k = 0;k<n;k++){
					for(int l = 0;l<m;l++){
						//if(size[get(k,l)]>5) cout<<k<<" "<<l<<endl;
						if(size[get(k,l)] == qnum+emptynum-1){
							return false;
						}
					}
				}
			}
			out = 0;	
		}
	}
	//cout<<flag<<endl;
	//cout<<qnum+emptynum-1<<endl;;
	//if(flag)
	return true;
	//else cout<<"not ";
}
void clean(){
	init();
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(mp[i][j] == 3){
				dfss(i,j);
			}
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(!mark[i][j]) mp[i][j] = 1,qnum--;
		}
	}
}
void show(){
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			cout<<mp[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			scanf(" %c",&tmp); 
			if(tmp == '#') mp[i][j] = 1,mark[i][j] = 1;
			else if(tmp == '?') mp[i][j] = 2,qnum++;
			else mp[i][j] = 3,emptynum++,mark[i][j] = 1;
		}
	}
	//show();
	clean();
	//show();
	if(judge_has()){
		if(!all_dfs()) return 0*printf("Ambiguous\n");
		else{
			//cout<<"here\n";
			for(int i = 0;i<n;i++){
				for(int j = 0;j<m;j++){
					if(mp[i][j] == 2 || mp[i][j] == 3) printf(".");
					else printf("#");
				}
				if(i != n-1) printf("\n");
			}
		}
	}
	else return 0*printf("Impossible\n");
}

 
