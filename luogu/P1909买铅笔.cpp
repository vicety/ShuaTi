#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, num;
int pen[3][2];
int res = INF;

int main(){
	cin >> n;
	for(int i = 0; i < 3; i++){
		cin>> pen[i][0] >> pen[i][1];
		if(!(n % pen[i][0])) num = n / pen[i][0];
		else num = n / pen[i][0] + 1;
		int tmp = pen[i][1] * num;
		if(tmp < res) res = tmp;	
	}
	printf("%d\n", res);
	return 0;
}
