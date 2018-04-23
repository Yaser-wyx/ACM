#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-15
 *  @Time: 21:43
 *  To change this template use File | Settings | File Templates.
 * 
 */


#define maxn 42
typedef long long int lli;
lli pre[maxn];
int n;

void form() {
    pre[1] = 3;
    pre[2] = 8;
    pre[3] = 22;
    for (int i = 4; i < maxn; i++) {

        pre[i] = 2 * pre[i - 1] + 2 * pre[i - 2];
    }
}

int HDU2047() {
    form();
    while (~scanf("%d", &n)) {
        printf("%lli\n", pre[n]);
    }

    return 0;
}