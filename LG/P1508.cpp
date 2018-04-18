#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-18
 *  @Time: 14:48
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 300
int n, m;
int matrix[maxn][maxn];
int dp[maxn][maxn];
int mv[3][2] = {{-1, -1},
                {-1, 0},
                {-1, 1}};
int ans = 0;


int P1508() {
    mset(dp, 0);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 3; k++) {
                int newx = i + mv[k][0];
                int newy = j + mv[k][1];
                if (newx >= 0 && newy >= 0 && newy <= m) {
                    dp[i][j] = max(dp[i][j], dp[newx][newy] + matrix[i][j]);
                }
            }
        }
    }
    printf("%d\n", dp[n + 1][(m + 1) >> 1]);
    return 0;
}
