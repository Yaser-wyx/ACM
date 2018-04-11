#include <bits/stdc++.h>
#define maxn  33

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-25
 *  @Time: 09:35
 *  To change this template use File | Settings | File Templates.
 * 
 */

int P1057() {
    int n, m;
    scanf("%d%d", &n, &m);
    int dp[maxn][maxn];//表示传k次到第i个人有多少种方法
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;//初始状态
    for (int k = 1; k <= m; k++) {
        dp[1][k] = dp[2][k - 1] + dp[n][k - 1];//球传m次到第i个人的方法数
        for (int i = 2; i <= n; i++) {
            dp[i][k] = dp[i + 1][k - 1] + dp[i - 1][k - 1];
        }
        dp[n][k] = dp[n - 1][k - 1] + dp[1][k - 1];
    }
    printf("%d\n", dp[1][m]);
    return 0;
}