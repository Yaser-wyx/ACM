#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-04
 *  @Time: 23:04
 *  To change this template use File | Settings | File Templates.
 * 
 */


#define maxn 100100
#define mid (l+r)>>1
#define left rt<<1
#define right rt<<1|1
#define lson l,m,left
#define rson m+1,r,right
int x, q;

int sum1[maxn << 2];
int lazy[maxn << 2];

void pushUp(int rt) {
    sum1[rt] = sum1[left] + sum1[right];

}

void pushDown(int rt, int ln, int rn) {
    if (lazy[rt]) {
        lazy[left] = lazy[rt];
        lazy[right] = lazy[rt];
        sum1[left] = lazy[left] * ln;
        sum1[right] = lazy[right] * rn;
        lazy[rt] = 0;
    }
}

void build(int l = 1, int r = x, int rt = 1) {
    if (l == r) {
        sum1[rt] = 1;
        return;
    }
    int m = mid;
    build(lson);
    build(rson);
    pushUp(rt);
}

void update(int L, int R, int num, int l, int r, int rt) {
    if (L <= l && R >= r) {
        //在区间内
        lazy[rt] = num;
        sum1[rt] = num * (r - l + 1);//替换
        return;
    }
    int m = mid;
    pushDown(rt, m - l + 1, r - m);
    if (L <= m)update(L, R, num, lson);
    if (R > m)update(L, R, num, rson);
    pushUp(rt);

}

int HDU1698() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d%d", &x, &q);
        memset(lazy, 0, sizeof(lazy));
        memset(sum1, 0, sizeof(sum1));
        build();
        while (q--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            update(a, b, c, 1, x, 1);
        }
        printf("Case %d: The total value of the hook is %d.\n", i, sum1[1]);

    }
    return 0;
}