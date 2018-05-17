#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-05-17
 *  @Time: 10:28
 *  To change this template use File | Settings | File Templates.
 *  线段树 区间更新 区间查询
 */
#define mid (l+r)>>1
#define left rt<<1
#define right rt<<1|1
#define lson l,m,left
#define rson m+1,r,right
#define maxn 100005
#define maxn2 10
int n, p, m;
lli mx[maxn << 2];
lli lazy[maxn << 2];

void pushDown(int rt, int ln, int rn) {
    if (lazy[rt]) {
        lazy[left] += lazy[rt];
        lazy[right] += lazy[rt];
        mx[left] += ln * lazy[rt];
        mx[right] += rn * lazy[rt];
        lazy[rt] = 0;
    }

}

inline void pushUp(int rt) {
    mx[rt] = mx[left] + mx[right];
}

void build(int l, int r, int rt) {
    if (l == r) {
        cin >> mx[rt];
        return;
    }
    int m = mid;
    build(lson);
    build(rson);
    pushUp(rt);
}

void update(int L, int R, int v, int l, int r, int rt) {
    if (L <= l && R >= r) {
        lazy[rt] += v;
        mx[rt] += (r - l + 1) * v;
        return;
    }
    int m = mid;
    pushDown(rt, m - l + 1, r - m);
    if (L <= m) {
        update(L, R, v, lson);
    }
    if (R > m) {
        update(L, R, v, rson);
    }
    pushUp(rt);
}

lli query(int L, int R, int l, int r, int rt) {
    if (L <= l && R >= r) {
        return mx[rt];
    }
    int m = mid;
    pushDown(rt, m - l + 1, r - m);
    lli ans = 0;
    if (L <= m) {
        ans += query(L, R, lson);
    }
    if (R > m) {
        ans += query(L, R, rson);
    }

    return ans;

}