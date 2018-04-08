#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-01
 *  @Time: 18:49
 *  To change this template use File | Settings | File Templates.
 * 
 */


#define maxn 100010
typedef long long int lli;

int x, q;
lli c[2][maxn];//简化为二维数组 0存差分数组 1存i*Ci

int lowbit(int x) {
    return x & (-x);
}

void update(int x, lli add, int t) {
    while (x <= x) {
        c[t][x] += add;
        x += lowbit(x);
    }
}

lli query(int x, int t) {
    lli ans(0);
    while (x > 0) {
        ans += c[t][x];
        x -= lowbit(x);
    }
    return ans;
}

lli ask(int pos) {
    lli ans(0);
    ans = (pos + 1) * query(pos, 0) - query(pos, 1);
    return ans;
}

int H() {
    scanf("%d%d", &x, &q);
    memset(c, 0, sizeof(c));
    int last(0);
    for (int i = 1; i <= x; i++) {
        int temp;
        scanf("%d", &temp);
        update(i, temp - last, 0);
        update(i, i * (temp - last), 1);
        last = temp;
    }
    char o;
    int a, b, c;
    while (q--) {
        getchar();
        scanf("%c", &o);
        if (o == 'Q') {
            scanf("%d%d", &a, &b);
            printf("%lli\n", ask(b) - ask(a - 1));
        } else {
            scanf("%d%d%d", &a, &b, &c);
            update(a, c, 0);
            update(b + 1, -c, 0);
            update(a, a * c, 1);
            update(b + 1, -c * (b + 1), 1);
        }

    }
    return 0;
}