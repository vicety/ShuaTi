#include<bits/stdc++.h>
using namespace std;
struct Point{
	long long x,y;
}a,b,c;
bool inLine(Point a,Point b,Point c){
	if((c.y-a.y)*(b.x-a.x) == (b.y-a.y)*(c.x-a.x)) return true;
	return false;
}
int main(){
	cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
	if(inLine(a,b,c)) return 0*printf("No\n");
	long long fbc = pow(b.x-a.x,2)+pow(b.y-a.y,2);
	long long fab = pow(b.x-c.x,2)+pow(b.y-c.y,2);
	if(fbc != fab) return 0*printf("No\n");
	printf("Yes\n");
	return 0;
} 

