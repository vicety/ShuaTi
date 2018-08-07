#include<bits/stdc++.h>
using namespace std;

int mp[5][5];
int vis[5][5];
int row, col, sx, sy, fx, fy;
int barr_num;

bool in_bound(int x, int y){
	return (x >= 0 && x < col) && (y >= 0 && y < row);
}

int dfs(int nx, int ny){
	int res = 0;
	if(nx == fx && ny == fy) return 1;
	vis[nx][ny] = 1;
	if(in_bound(nx + 1, ny) && !mp[nx + 1][ny] && !vis[nx + 1][ny]) res += dfs(nx + 1, ny);
	if(in_bound(nx - 1, ny) && !mp[nx - 1][ny] && !vis[nx - 1][ny]) res += dfs(nx - 1, ny);
	if(in_bound(nx, ny + 1) && !mp[nx][ny + 1] && !vis[nx][ny + 1]) res += dfs(nx, ny + 1);
	if(in_bound(nx, ny - 1) && !mp[nx][ny - 1] && !vis[nx][ny - 1]) res += dfs(nx, ny - 1);
	vis[nx][ny] = 0;
	return res;
}

int main(){
	cin>>row>>col>>barr_num>>sx>>sy>>fx>>fy;
	sx--;
	sy--;
	fx--;
	fy--;
	for(int i = 0, x, y; i < barr_num; i++){
		cin>>x>>y;
		x--;
		y--;
		mp[x][y] = 1;
	}
	printf("%d\n", dfs(sx, sy));
	return 0;
} 
