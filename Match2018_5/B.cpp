#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-01
 *  @Time: 18:59
 *  To change this template use File | Settings | File Templates.
 * 
 */


typedef long long int lli;
#define maxn 100010
lli num[maxn] = {0};
int x;

int lowbit(int x) {
    return x & (-x);
}

void update(int x, lli add) {
    while (x <= x) {
        num[x] += add;
        x += lowbit(x);
    }
}

lli query(int x) {
    lli ans(0);
    while (x > 0) {
        ans += num[x];
        x -= lowbit(x);
    }
    return ans;
}

int B() {
    int q;
    scanf("%d%d", &x, &q);
    for (int i = 1; i <= x; i++) {
        lli temp;
        scanf("%lli", &temp);
        update(i, temp);
    }
    int f, x, y;
    while (q--) {
        scanf("%d%d%d", &f, &x, &y);
        if (f == 1) {
            //更新
            update(x, y);
        } else {
            //查询
            lli temp = query(y) - query(x - 1);
            printf("%lli\n", temp);
        }
    }
    return 0;
}