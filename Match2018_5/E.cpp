#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-01
 *  @Time: 21:50
 *  To change this template use File | Settings | File Templates.
 * 
 */

typedef long long int lli;
#define maxn 1010
lli sum1[maxn][maxn] = {0};
int x;
bool lamp[maxn][maxn] = {false};

int lowbit(int x) {
    return x & (-x);
}

void update(int x, int y, int add) {
    for (int i = x; i <= x; i += lowbit(i)) {
        for (int j = y; j <= x; j += lowbit(j)) {
            sum1[i][j] += add;
        }
    }
}

lli query(int x, int y) {
    lli ans(0);
    for (int i = x; i > 0; i -= lowbit(i)) {
        for (int j = y; j > 0; j -= lowbit(j)) {
            ans += sum1[i][j];
        }
    }
    return ans;
}

int E() {
    int q;
    scanf("%d%d", &x, &q);
    int temp(0);
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j <= x; j++) {
            scanf("%d", &temp);
            lamp[i][j] = temp != 0;
            update(i, j, temp);
        }
    }
    int f, x1, y1, x2, y2;
    while (q--) {
        scanf("%d", &f);
        if (f == 1) {
            //更新
            scanf("%d%d", &x1, &y1);
            if (lamp[x1][y1]) {
                //亮
                update(x1, y1, -1);
                lamp[x1][y1] = false;
            } else {
                update(x1, y1, 1);
                lamp[x1][y1] = true;
            }
        } else {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            lli ans = query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
            printf("%lli\n", ans);
        }
    }

    return 0;
}