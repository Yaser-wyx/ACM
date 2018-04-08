#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-03-27
 *  @Time: 15:47
 *  To change this template use File | Settings | File Templates.
 * 
 */


#define maxn 22
int n, m, cx, cy;
long long dp[maxn][maxn];
int x[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int y[8] = {2, -2, 1, -1, 2, -2, 1, -1};

void horse() {
    dp[cx][cy] = -1;
    for (int i = 0; i < 8; i++) {
        int tx = cx + x[i];
        int ty = cy + y[i];
        if (tx >= 0 && ty >= 0 && tx <= n && ty <= m) {
            dp[tx][ty] = -1;
        }
    }
}

int p8() {
    scanf("%d%d%d%d", &n, &m, &cx, &cy);
    memset(dp, 0, sizeof(dp));
    horse();
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i][j] == -1) {
                continue;
            }
            if (i > 0) {
                if (dp[i - 1][j] != -1) {
                    dp[i][j] += dp[i - 1][j];
                }
            }
            if (j > 0) {
                if (dp[i][j - 1] != -1) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
    }
    printf("%lli\n", dp[n][m]);

    return 0;
}