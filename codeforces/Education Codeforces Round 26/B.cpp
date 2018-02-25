#include<bits/stdc++.h>
using namespace std;
int n,m;
char rec[102][102],tmp,a,b,c;
//bool flag;
bool check_row(){
	a = rec[0][0],b = rec[n/3][0],c = rec[n*2/3][0];
	for(int i = 0;i<n/3;i++){
		for(int j = 0;j<m;j++){
			if(rec[i][j] != a) return false;
			if(rec[i+n/3][j] != b) return false;
			if(rec[i+n*2/3][j] != c) return false;
		}
	}
	return true;
}
bool check_line(){
	a = rec[0][0],b = rec[0][m/3],c = rec[0][m*2/3];
	for(int i = 0;i<m/3;i++){
		for(int j = 0;j<n;j++){
			if(rec[j][i] != a) return false;
			if(rec[j][i+m/3] != b) return false;
			if(rec[j][i+m*2/3] != c) return false;
		}
	}
	return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			scanf(" %c",&rec[i][j]);
			if(rec[i][j]!='R'&&rec[i][j]!='G'&&rec[i][j]!='B'){
				cout<<"NO";
				return 0;
			}
		}
	}
	if((n%3) && (m%3)){
		cout<<"NO";
		return 0;
	}
	bool flag = false;
	if(!(n%3) && (m%3)){
		if(check_row()) flag = true;
	}
	else if((n%3) && !(m%3)){
		if(check_line()) flag = true;
	}
	else{
		if(check_row()||check_line()) flag = true;
	}
	if(flag) cout<<"YES";
	else cout<<"NO";
	return 0;
}
//860 hacked...
