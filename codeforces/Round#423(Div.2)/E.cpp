#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x = 0,f= 1; char ch = getchar();
	while(ch<'0' || ch>'9') {if(ch == '-') f=-1;ch = getchar();}
	while(ch>='0'&&ch<='9') {x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

const int maxn = 100010;
int dp[4][11][11][maxn], has[200];
void init(){
	memset(dp, 0, sizeof(dp));
	has['A'] = 0;
	has['T'] = 1;
	has['C'] = 2;
	has['G'] = 3;
}

int lowbit(int k){
	return k&(-k);
}

void add(int pos, int type, int val){
	for(int i = pos;i<maxn;i+=lowbit(i)){
		for(int j = 1;j<=10;j++){
			dp[type][j][pos%j][i] += val;
		}
	}
}

int query(int type, int len, int mod, int x){
	int ans = 0;
	for(int i = x;i>0;i-=lowbit(i)){
		ans += dp[type][len][mod][i];
	}
	return ans;
}

int sum(int l ,int r, int mod, int type, int len){
	return query(type, len ,mod, r) - query(type, len, mod, l-1);
}

char s[maxn];

int main(){
	init();
	scanf("%s", &s[1]);
	int l = strlen(s+1);
	for(int i = 1;i<=l;i++) add(i, has[s[i]], 1);
	char ch[111];
	int q, a, b, c; q =read();
	while(q--){
		a = read();
		if(a == 1){
			b = read(); scanf("%s", ch);
			add(b, has[s[b]], -1);
			add(b, has[ch[0]], 1);
			s[b] = ch[0];
		}
		else{
			b = read(), c = read(), scanf("%s", ch);
			int len = strlen(ch);
			int ans = 0;
			for(int i = 0;i<len;i++){
				ans += sum(b, c, (i+b)%len, has[ch[i]], len);
			}
			printf("%d\n", ans);
		}
	}
	return 0; 
}


