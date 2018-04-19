#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-18
 *  @Time: 18:36
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 60
int n, m;
int f[maxn << 1][maxn][maxn];
int matrix[maxn][maxn];

inline int max4(int a, int b, int c, int d) {
    return max(a, max(b, max(c, d)));
}

int P1006_2() {
    mset(f, 0);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int step = 2; step <= n + m - 1; step++) {//步数
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (step - i + 1 < 1 || step - j + 1 < 1) {
                    continue;
                }
                f[step][i][j] = max4(f[step - 1][i][j], f[step - 1][i - 1][j - 1], f[step - 1][i - 1][j],
                                     f[step - 1][i][j - 1]) + matrix[i][step - i + 1] + matrix[j][step - j + 1];
                if (i == j) {
                    f[step][i][j] -= matrix[i][step - i + 1];
                }
            }
        }
    }
    printf("%d\n", f[n + m - 1][n][n]);
    return 0;
}
