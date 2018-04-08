#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-27
 *  @Time: 15:58
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define maxn 200
int n;
int dp[maxn];

int P9() {
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));
    dp[1] = 3;
    dp[2] = 6;
    dp[3] = 6;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
    }
    printf("%d", dp[n]);
    return 0;
}