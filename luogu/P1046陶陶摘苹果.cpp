#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e7 + 10;

int temp[maxn];
int n;
int now, res;
int _prev = -1;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp[i];
		if(temp[i] > _prev){
			now++;	
			if(now > res) res = now;
		} 
		else now = 1; 
		_prev = temp[i];
	}
	return 0 * printf("%d\n", res);
}
