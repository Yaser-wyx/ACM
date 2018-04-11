#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-16
 *  @Time: 20:16
 *  To change this template use File | Settings | File Templates.
 * 
 */


#define maxn 33
typedef long long int lli;

lli ans[maxn];

void form() {
    ans[0] = 1;
    ans[2] = 3;
    for (int i = 4; i < maxn; i += 2) {
        ans[i] = 4 * ans[i - 2] - ans[i - 4];
    }
}

int HDU1143() {
    int n;
    form();
    while (~scanf("%d", &n)) {
        if (n == -1) {
            break;
        }
        printf("%lld\n", ans[n]);
    }
    return 0;
}