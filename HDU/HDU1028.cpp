#include <bits/stdc++.h>

#define maxn 130
using namespace std;
int dp[maxn];

/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-02-28
 *  @Time: 17:11
 *  To change this template use File | Settings | File Templates.
 * 
 */

int HDU1028() {
    int n;
    while (~scanf("%d", &n)) {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                dp[j] += dp[j - i];
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}