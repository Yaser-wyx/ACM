#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-06
 *  @Time: 16:12
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define maxn 205

struct Seg {
    double l, r, h;
    int d;

    Seg() {}

    Seg(double l, double r, double h, int d) : l(l), r(r), h(h), d(d) {}

    bool operator<(const Seg &s) const { return h < s.h; }
} a[maxn];

int x;
int cnt[maxn << 2];
double sum1[maxn << 2], all[maxn];
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

void push_up(int l, int r, int rt) {
    if (cnt[rt]) {//该区间被覆盖过
        sum1[rt] = all[r + 1] - all[l];
    } else if (l == r) {//叶子结点
        sum1[rt] = 0;
    } else {
        sum1[rt] = sum1[rt << 1] + sum1[rt << 1 | 1];
    }
}

void update(int L, int R, int v, int l, int r, int rt) {
    if (L <= l && R >= r) {
        //当前区域在更新范围内
        cnt[rt] += v;
        push_up(l, r, rt);
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m)update(L, R, v, lson);
    if (R > m)update(L, R, v, rson);
    push_up(l, r, rt);
}

int HDU1542() {
    int k = 0;
    while (~scanf("%d", &x)) {
        if (!x)break;
        double x1, y1, x2, y2;
        for (int i = 1; i <= x; i++) {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            a[i] = Seg(x1, x2, y1, 1);
            a[i + x] = Seg(x1, x2, y2, -1);
            all[i] = x1;
            all[i + x] = x2;
        }
        x <<= 1;
        sort(a + 1, a + 1 + x);
        sort(all + 1, all + 1 + x);
        int m = (unique(all + 1, all + 1 + x) - all - 1);
        memset(cnt, 0, sizeof(cnt));
        memset(sum1, 0, sizeof(sum1));
        double ans = 0;
        for (int i = 1; i < x; i++) {
            int l = lower_bound(all + 1, all + 1 + m, a[i].l) - all;
            int r = (lower_bound(all + 1, all + 1 + m, a[i].r) - all);
            if (l < r)update(l, r - 1, a[i].d, 1, m, 1);
            ans += sum1[1] * (a[i + 1].h - a[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", ++k, ans);

    }
    return 0;
}