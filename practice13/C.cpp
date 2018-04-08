#include <bits/stdc++.h>

using namespace std;

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-17
 *  @Time: 10:21
 *  To change this template use File | Settings | File Templates.
 * 
 */


#define maxn 100005

int C() {
    int n, k;
    scanf("%d%d", &n, &k);
    char ans[maxn];
    memset(ans, '\0', sizeof(ans));
    scanf("%s", ans + 1);
    for (int i = 2; i <= n && k > 0; i++) {
        int x = i - 1;
        if (ans[i] == '7' && ans[x] == '4') {
            if (x % 2 == 0) {
                //偶数
                if (x - 1 >= 0 && ans[x - 1] == '4') {
                    if (k % 2 != 0) {
                        ans[x] = '7';
                    }
                    break;
                } else {
                    ans[x] = '7';
                }
            } else {
                //奇数
                if (x + 2 < n && ans[x + 2] == '7') {
                    if (k % 2 != 0) {
                        ans[x + 1] = '4';
                    }
                    break;
                } else {
                    ans[x + 1] = '4';
                }
            }
            k--;
        }
    }
    printf("%s\n", ans + 1);
    return 0;
}