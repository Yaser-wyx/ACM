#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-23
 *  @Time: 16:39
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define maxn 1010
#define maxm 150
int n, m, k;
int puzzle[maxm][maxm];
int dp[maxm][maxm];
int mv[4][2] = {{1,  0},
                {-1, 0},
                {0,  1},
                {0,  -1}};

int dfs(int x, int y) {
    if (dp[x][y] != 1) {
        return dp[x][y];
    }
    loop(i, 0, 3) {
        int new_x = x + mv[i][0];
        int new_y = y + mv[i][1];
        if (new_x > 0 && new_y > 0 && new_x <= n && new_y <= m && puzzle[new_x][new_y] < puzzle[x][y]) {
            dp[x][y] = max(dfs(new_x, new_y) + 1, dp[x][y]);
        }
    }
    return dp[x][y];
}

int P1434() {
    scanf("%d%d", &n, &m);
    loop(i, 1, n) {
        loop(j, 1, m) {
            scanf("%d", &puzzle[i][j]);
        }
    }
    loop(i, 0, n) {
        loop(j, 0, m) {
            dp[i][j] = 1;
        }
    }
    int ans = 0;
    loop(i, 1, n) {
        loop(j, 1, m) {
            dp[i][j] = dfs(i, j);
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}