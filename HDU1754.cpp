#include <bits/stdc++.h>

using namespace std;
#define mid (l+r)>>1
#define left rt<<1
#define right rt<<1|1
#define lson l,m,left
#define rson m+1,r,right
#define maxn 200010
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-11
 *  @Time: 9:23
 *  To change this template use File | Settings | File Templates.
 * 
 */
int Max[maxn << 2];
int x, m;

void PushUp(int rt) {
    Max[rt] = max(Max[left], Max[right]);
}

void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", &Max[rt]);
        return;
    }
    int m = mid;
    build(lson);
    build(rson);
    PushUp(rt);
}

void update(int index, int num, int l, int r, int rt) {
    if (l == r) {
        Max[rt] = num;
        return;
    }
    int m = mid;
    if (index <= m) {
        update(index, num, lson);
    } else {
        update(index, num, rson);
    }
    PushUp(rt);
}

int Query(int index_l, int index_r, int l, int r, int rt) {
    if (index_l <= l && index_r >= r) {
        return Max[rt];
    }
    int m = mid;
    int ans(0);
    if (index_l <= m)ans = max(ans, Query(index_l, index_r, lson));
    if (index_r > m)ans = max(ans, Query(index_l, index_r, rson));
    return ans;

}

int HDU1754() {

    while (~scanf("%d%d", &x, &m)) {
        build(1, x, 1);
        while (m--) {
            getchar();
            char q;
            int a, b;
            scanf("%c%d%d", &q, &a, &b);
            if (q == 'Q') {
                int ans = Query(a, b, 1, x, 1);
                printf("%d\n", ans);
            } else {
                update(a, b, 1, x, 1);
            }
        }
    }
    return 0;
}