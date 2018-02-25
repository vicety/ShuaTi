#include<bits/stdc++.h>
using namespace std;
double r,d,x[100100],y[100100],ra[100100];
int n;
int cnt;
double tocen;
double dis(int x,int y){
	return sqrt((pow(x,2)+pow(y,2)));
}
bool check(double dis,double rr){
	if(dis-rr>=r-d && dis+rr<=r) return true;
	return false;
}
int main(){
	scanf("%lf%lf",&r,&d);
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%lf%lf%lf",&x[i],&y[i],&ra[i]);
	}
	for(int i = 0;i<n;i++){
		tocen = dis(x[i],y[i]);
		if(check(tocen,ra[i])) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
} 
