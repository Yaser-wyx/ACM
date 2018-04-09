#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-08
 *  @Time: 22:41
 *  To change this template use File | Settings | File Templates.
 * 
 */
typedef long long int lli;

#define maxn 1010
long n, m;
lli matrix[maxn][maxn];
lli ans[maxn][maxn];

int main() {
    while (~scanf("%li%li", &n, &m)) {

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%lli", &matrix[i][j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if ((matrix[i][j] % 2 + 2) % 2 != (matrix[j][i] % 2 + 2) % 2) {
                    matrix[i][j] += m;
                }
                ans[i][j] = (abs(matrix[i][j] - matrix[j][i]) / 2) * (matrix[i][j] > matrix[j][i] ? 1 : -1);
                ans[j][i] = (abs(matrix[i][j] - matrix[j][i]) / 2) * (matrix[i][j] < matrix[j][i] ? 1 : -1);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%lli", (ans[i][j] % m + m) % m);
                if (j != n) {
                    printf(" ");
                }
            }
            printf("\n");
        }

    }
    return 0;
}