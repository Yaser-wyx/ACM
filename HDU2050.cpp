#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-16
 *  @Time: 16:31
 *  To change this template use File | Settings | File Templates.
 * 
 */

int HDU2050() {
    int c;
    scanf("%d", &c);
    while (c--) {
        int n;
        scanf("%d", &n);
        int ans = 2 * n * n - n + 1;
        printf("%d\n", ans);
    }
    return 0;
}