#include<bits/stdc++.h>
using namespace std;

int res, maxx;

int main(){
	for(int i = 1, a ,b; i <= 7; i++){
		cin >> a >> b;
		if(a + b > 8 && a + b > maxx){
			maxx = a + b;
			res = i;
		}
	}
	printf("%d\n", res);
	return 0;
}
