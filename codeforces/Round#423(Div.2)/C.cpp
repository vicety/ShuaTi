// 这里是并查集写法 
// 线段树单点也可以 nlogn大概 2e7 
#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
char s[N], s1[N];
int fa[N];
int find(int x){
	return x == fa[x]?x:fa[x] = find(fa[x]);
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0;i<N;i++) s[fa[i] = i] = 'a';
	int maxv = 0;
	while(n--){
		scanf("%s", s1);
		int l = strlen(s1);
		int m, x;
		scanf("%d", &m);
		while(m--){
			scanf("%d", &x);
			--x;
			maxv = max(maxv, x+l);
			int y = x;
			while((y = find(y)) < x+l){
				s[y] = s1[y-x];
				fa[y] = y+1;  
			}
		}
	}
	s[maxv] = '\0';
	return 0*printf("%s\n",s);
}

/* 我觉得重点还是分清id和ans 
#include<bits/stdc++.h>
using namespace std;
#define _____ ios::sync_with_stdio(false); cin.tie(0);
#define ull unsigned long long
#define ll long long
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1

typedef pair<int, int>pii;
typedef pair<ll, ll>pll;
typedef pair<double, double>pdd;

const double eps = 1e-6;
const int MAXN = 350005;
const int MAXM = 5005;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const double FINF = 1000000000000000.0;
const ll MOD = 1000000007;
const double PI = acos(-1);

char ans[2000005];
int vis[8000005];
string s;
void add(int l, int r, int id, int L, int R) {
	if (vis[id] == r - l + 1)return;
	if (l == r) {
		ans[l] = s[l - L];
		vis[id] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	if (R <= mid)add(lson, L, R);
	else if (L > mid)add(rson, L, R);
	else
	{
		add(lson, L, R);
		add(rson, L, R);
	}
	vis[id] = vis[id << 1] + vis[id << 1 | 1];
}
int main()
{
	memset(vis, 0, sizeof(vis));
	int n, x, maxx = 0; scanf("%d", &n);
	for (int i = 0; i <= 2000000; ++i)ans[i] = 'A';
	for (int i = 0; i < n; ++i) {
		cin >> s;
		int t; scanf("%d", &t);
		int len = s.size();
		while (t--) {
			scanf("%d", &x); maxx = max(maxx, x + len - 1);
			add(1, 2000000, 1, x, x + len - 1);
		}
	}
	for (int i = 1; i <= maxx; ++i) {
		if (ans[i] == 'A')printf("a");
		else printf("%c", ans[i]);
	}
}
*/
