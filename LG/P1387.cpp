#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-18
 *  @Time: 18:51
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 150
int n, m;
int matrix[maxn][maxn];


int P1387() {
    int dp[maxn][maxn];
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (matrix[i][j]) {
                if (dp[i][j - 1] == dp[i - 1][j] && dp[i - 1][j]) {
                    dp[i][j] = dp[i - 1][j - 1] + matrix[i][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
                }
            }
            ans = max(dp[i][j], ans);
        }
    }
    printf("%d\n", ans);
    return 0;
}
