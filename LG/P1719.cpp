#include <bits/stdc++.h>

#define infinitesimal  -2100000000
using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-24
 *  @Time: 08:43
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define loop3(a, b, c) for(int a=b;a<c;a++)
#define loop4(a, b, c) for(int a=b;a>c;a--)
#define maxn 150
#define maxm 20
int n, m, t;
int matrix[maxn][maxn];
int ans = infinitesimal;
int temp[maxn];
int dp[maxn];

void Arrsum() {
    mset(dp, 0);
    loop(i, 1, n) {
        dp[i] = max(dp[i], dp[i - 1] + temp[i]);
        ans = max(ans, dp[i]);
    }
}

void MatrixSum() {
    loop(i, 1, n) {
        mset(temp, 0);
        loop(j, i, n) {
            loop(k, 1, n) {
                temp[k] += matrix[j][k];
            }
            Arrsum();
        }
    }
}

int P1719() {
    scanf("%d", &n);
    loop(i, 1, n) {
        loop(j, 1, n) {
            scanf("%d", &matrix[i][j]);
        }
    }
    MatrixSum();
    printf("%d\n", ans);
    return 0;
}