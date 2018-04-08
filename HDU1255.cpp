#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-07
 *  @Time: 16:31
 *  To change this template use File | Settings | File Templates.
 * 
 */


#define maxn 2010
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

struct Seg {
    double l, r, h;
    int d;

    Seg(double l, double r, double h, int d) : l(l), r(r), h(h), d(d) {}

    Seg() {}

    bool operator<(const Seg &rhs) const {
        return h < rhs.h;
    }

} rectangle[maxn];

int cnt[maxn << 2];
double sum1[maxn << 2];
double sum2[maxn << 2];
double x[maxn << 2];

void push_up(int rt, int l, int r) {
    if (cnt[rt]) {
        sum1[rt] = x[r + 1] - x[l];
    } else if (l == r) {
        sum1[rt] = 0;
    } else {
        sum1[rt] = sum1[rt << 1] + sum1[rt << 1 | 1];
    }

    if (cnt[rt] == 1) {
        sum2[rt] = sum1[rt << 1] + sum1[rt << 1 | 1];
    } else if (cnt[rt] >= 2) {
        sum2[rt] = x[r + 1] - x[l];
    } else if (l == r) {
        sum2[rt] = 0;
    } else if (cnt[rt] == 0) {
        sum2[rt] = sum2[rt << 1] + sum2[rt << 1 | 1];
    }

}

void update(int L, int R, int v, int l, int r, int rt) {
    if (L <= l && R >= r) {
        cnt[rt] += v;
        push_up(rt, l, r);
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m)update(L, R, v, lson);
    if (R > m)update(L, R, v, rson);
    push_up(rt, l, r);
}

int HDU1255() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        memset(sum1, 0, sizeof(sum1));
        memset(sum2, 0, sizeof(sum2));
        memset(x, 0, sizeof(x));
        double x1, x2, y1, y2;
        int index1(0), index2(0);
        for (int i = 0; i < n; i++) {//数据读取
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            rectangle[index1++] = Seg(x1, x2, y1, 1);
            rectangle[index1++] = Seg(x1, x2, y2, -1);
            x[index2++] = x1;
            x[index2++] = x2;
        }
        sort(rectangle, rectangle + index1);
        sort(x, x + index2);
        int res = 1;
        for (int i = 1; i < index1; i++) {
            if (x[i] != x[i - 1]) {
                x[res++] = x[i];
            }
        }
        double ans = 0;
        for (int i = 0; i < index1 - 1; i++) {
            int l = lower_bound(x, x + res, rectangle[i].l) - x;
            int r = lower_bound(x, x + res, rectangle[i].r) - x - 1;
            update(l, r, rectangle[i].d, 0, res - 1, 1);
            ans += sum2[1] * (rectangle[i + 1].h - rectangle[i].h);
        }
        printf("%.2lf\n", ans);

    }
    return 0;
}