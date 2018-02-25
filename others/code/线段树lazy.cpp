#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
using namespace std;
//PushUp(rt)��ͨ����ǰ�ڵ�rt��ֵ�ݹ����ϸ��µ����ڵ�
//PushDown(rt)��ͨ����ǰ�ڵ�rt�ݹ�����ȥ����rt�ӽڵ��ֵ
// l m �� rt ������ͬһ�������µģ�l m ����ʵ˳�� rt������index
//��Ϊ��
typedef long long LL;
const int N = 1e6 + 10;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
LL sum[N << 2];
LL laz[N << 2];
char str[10];
int l, r;
inline void pushup(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

inline void pushdown(int rt, int l, int r) {
	if (!laz[rt]) return;
	laz[rt << 1] += laz[rt];
	laz[rt << 1 | 1] += laz[rt];
	int m = (l + r) >> 1;
	sum[rt << 1] += (LL)laz[rt] * (LL)(m - l + 1);
	sum[rt << 1 | 1] += (LL)laz[rt] * (LL)(r - m);
	laz[rt] = 0;
}

void build(int l, int r, int rt) {
	laz[rt] = 0;
	if (l == r) {
		scanf("%lld", sum + rt);
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(rt);
}

LL sum_query(int L, int R, int l, int r, int rt) { //L R�Ǳ��β�ѯ������
	pushdown(rt, l, r); //����Ͳ�pushdown
	if (L <= l && r <= R) return sum[rt]; // ��ȫ����
	int m = (l + r) >> 1;
	if (L > m) return sum_query(L, R, rson);
	if (R <= m) return sum_query(L,R,lson);
	return sum_query(L, R, lson) + sum_query(L, R, rson);
}

void add(int L, int R, LL d, int l, int r, int rt) {
	pushdown(rt, l, r); // ͬ�� �����ľͲ�push
	if (L <= l&&r <= R) {
		sum[rt] += (LL)d*(LL)(r - l + 1);
		laz[rt] += (LL)d;
		return;
	}
	int m = (l + r) >> 1;
	if (L <= m) add(L, R, d, lson);
	if (R > m) add(L, R, d, rson);
	pushup(rt);
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	build(1, n, 1);
	while (q--) {
		scanf("%s %d %d", str, &l, &r);
		if (str[0] == 'C'){
			LL d; scanf("%lld", &d);
			add(l, r, d, 1, n, 1);
		}
		else printf("%lld\n", sum_query(l, r, 1, n, 1));
	}
	return 0;
}
