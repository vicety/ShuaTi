#include<iostream>
#include<cstdio>
using namespace std;
char c1,c2;
int n;
int fst,scd;
int getnum(char c){
	if(c == '^') return 0;
	else if(c == '>') return 1;
	else if(c == 'v') return 2;
	else return 3;
}
int main(){
	scanf(" %c %c",&c1,&c2);
	fst = getnum(c1),scd = getnum(c2);
	scanf("%d",&n);
	if((scd-fst+4)%4 == 2 || scd == fst) return 0*printf("undefined");
	if((scd-fst+4)%4 == n%4) return 0*printf("cw");
	else return 0*printf("ccw");
	return 0;
}
