#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int now, bank, need;

int main(){
	for(int i = 1; i <= 12; i++){
		now += 300;
		cin >> need;
		if(now < need) return 0 * printf("-%d\n", i);
		now -= need;
		bank += (now / 100) * 100;
		now %= 100;
	}
	return 0 * printf("%.0lf\n", bank * 1.2 + now);
}
