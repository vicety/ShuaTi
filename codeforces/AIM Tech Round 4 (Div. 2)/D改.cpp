#include<cstdio>
int n, s, x, cnt, q[1000], maxi = -1;
int main() {
    scanf("%d%d%d", &n, &s, &x);
    for (int i = 0; i < 1000; i++) q[i] = i*(1000000009LL) % n * 1000000007 % n + 1;

    int v, nxt;
    for (int i = 0; i < 1000; i++) {
        printf("? %d\n", q[i]);
        fflush(stdout);
        scanf("%d %d", &v, &nxt);
        if (v <= x && maxi < v) maxi = v, s = nxt;
    }
    while (~s && maxi < x) {
        printf("? %d\n", s);
        fflush(stdout);
        scanf("%d %d", &v, &nxt);
        maxi = v;
        s = nxt;
    }
    printf("! %d", maxi < x ? -1 : maxi);
    fflush(stdout);
    return 0;
}
