#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<deque>
#include<algorithm>
#define maxn 100100
#define REP(I,N) for(int I = 0;I<N;I++)
#define REP1(I,N) for(int I = 1;I<=N;I++)
#define INF 0x3f3f3f3f
#define MP(X,Y) make_pair(x,y)
#define CLR(A,X) memset(A,X,sizeof(A))
#define PB(X) push_back(X)
#define long long LL
using namespace std;
int seq[maxn];
int qmax[maxn];
int qmin[maxn];
//int seq[maxn];
int n, m, k;

int main() {
	while (scanf("%d%d%d", &n, &m, &k) == 3) {
		//scanf("%d %d", &m, &k);
		REP1(i, n)
			scanf("%d", seq + i);
		int ans = 0;
		int rear1, front1, rear2, front2;
		rear1 = front1 = 0;
		rear2 = front2 = 0;
		int now = 0;
		REP1(i, n) {
			while (front1<rear1 && seq[qmax[rear1 - 1]] < seq[i]) rear1--;
			qmax[rear1++] = i;
			while (front2<rear2 && seq[qmin[rear2 - 1]] > seq[i]) rear2--;
			qmin[rear2++] = i;
			while (front1<rear1 && front2<rear2 && seq[qmax[front1]] - seq[qmin[front2]]>k) {
				if (qmax[front1]<qmin[front2]) {
					now = qmax[front1++];
				}
				else {
					now = qmin[front2++];
				}
			}
			if (front1<rear1 && front2<rear2 && seq[qmax[front1]] - seq[qmin[front2]] >= m) {
				ans = max(ans, i - now);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
