#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-16
 *  @Time: 10:46
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define maxn 22
int n;
typedef long long int lli;
lli pre[maxn];
double ans[maxn];

void form() {
    pre[1] = 0;
    pre[2] = 1;
    ans[1] = 0;
    ans[2] = 50;
    lli N = 2;
    for (int i = 3; i < maxn; i++) {
        N *= i;
        pre[i] = (i - 1) * (pre[i - 1] + pre[i - 2]);
        ans[i] = ((double) pre[i] / (double) N) * 100;
    }
}

int HDU2048() {
    form();
    scanf("%d",&n);
    int x;
    while (n--) {
        scanf("%d",&x);
        printf("%.2f%%\n", ans[x]);

    }
    return 0;
}