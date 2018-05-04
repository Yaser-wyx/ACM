#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-27
 *  @Time: 15:49
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define lson index<<1
#define rson (index<<1) +1
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 30
#define maxm 10005
int n, b, k, t, x, y, z;
int matrix[maxn][maxn];
int dp[maxn][maxn][maxn];

int P1004() {
    mset(matrix, 0);
    scanf("%d", &n);
    while (~scanf("%d%d%d", &x, &y, &z)) {
        if (x + y + z == 0) {
            break;
        }
        matrix[x][y] = z;
    }
    loop(step, 1, n << 1) {
        loop(x1, 1, n) {
            loop(x2, 1, n) {
                if (step - x1 < 1 || step - x2 < 1) {
                    continue;
                }
                dp[step][x1][x2] = max(dp[step - 1][x1][x2], max(dp[step - 1][x1 - 1][x2],
                                                                 max(dp[step - 1][x1 - 1][x2 - 1],
                                                                     dp[step - 1][x1][x2 - 1]))) +
                                   matrix[x1][step - x1] + matrix[x2][step - x2];
                if (x1 == x2) {
                    dp[step][x1][x2] -= matrix[x1][step - x1];
                }
            }
        }
    }
    cout << dp[n * 2][n][n];
    return 0;
}
