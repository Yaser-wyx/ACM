#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-18
 *  @Time: 16:41
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 60
int n, m;
int f[maxn][maxn][maxn][maxn];
int matrix[maxn][maxn];

inline int max4(int a, int b, int c, int d) {
    return max(a, max(b, max(c, d)));
}

int P1006() {
    mset(f, 0);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                for (int l = 1; l <= m; l++) {
                    f[i][j][k][l] = max4(f[i - 1][j][k - 1][l], f[i - 1][j][k][l - 1], f[i][j - 1][k - 1][l],
                                         f[i][j - 1][k][l - 1]) + matrix[i][j] + matrix[k][l];
                    if (i == k && j == l) {
                        f[i][j][k][l] -= (matrix[i][j]);
                    }
                }
            }
        }
    }
    printf("%d\n", f[n][m][n][m]);
    return 0;
}
