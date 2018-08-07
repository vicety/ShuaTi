#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e2 + 10;

int fish[maxn];
int res[maxn];
int n;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> fish[i];
		for(int j = 0; j < i; j++){
			if(fish[j] < fish[i]) res[i]++;
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d%c", res[i], i == n - 1 ? '\n' : ' ');
	} 
	return 0;
}
