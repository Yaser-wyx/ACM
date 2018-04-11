#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-04
 *  @Time: 20:03
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define maxn 100010
int x;
int sum1[maxn];

int lowbit(int x) {
    return x & -x;
}

void update(int x, int add) {
    while (x <= x) {
        sum1[x] += add;
        x += lowbit(x);
    }
}

int query(int x) {
    int ans(0);
    while (x > 0) {
        ans += sum1[x];
        x -= lowbit(x);
    }
    return ans;
}

int HDU1556() {
    while (~scanf("%d", &x)) {
        if (x == 0)break;
        memset(sum1, 0, sizeof(sum1));
        int a, b;
        for (int i = 0; i < x; i++) {
            scanf("%d%d", &a, &b);
            update(a, 1);
            update(b + 1, -1);
        }
        for (int i = 1; i <= x; i++) {
            printf("%d", query(i));
            if (i != x) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}