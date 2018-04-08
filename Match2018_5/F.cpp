#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-02-25
 *  @Time: 23:08
 *  To change this template use File | Settings | File Templates.
 * 
 */

int F() {
    int n;
    while (~scanf("%d", &n)) {
        int ans = n % 9;//同余定理
        if (ans == 0) {
            ans = 9;
        }
        printf("%d", ans);
    }
    return 0;
}
