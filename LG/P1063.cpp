#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-19
 *  @Time: 17:24
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define maxn 210
#define maxm 50
int n, m;


int P1063() {
    pair<lli, lli> matrix[maxn];
    int temp[maxn];
    lli dp[maxn][maxn];
    scanf("%d", &n);
    loop(i, 1, n) {
        scanf("%d", &temp[i]);
    }
    loop(i, 1, n - 1) {
        matrix[i].first = temp[i];
        matrix[i].second = temp[i + 1];
        matrix[i + n].first = temp[i];
        matrix[i + n].second = temp[i + 1];
    }
    matrix[n].first = temp[n];
    matrix[n].second = temp[1];
    matrix[2 * n].first = temp[n];
    matrix[2 * n].second = temp[1];
    mset(dp, 0);
    loop(len, 2, n) {
        for (int l = 1; l + len <= 2 * n; l++) {
            int r = l + len - 1;
            for (int k = l; k + 1 <= r; k++) {
                dp[l][r] = max(dp[l][r],
                               dp[l][k] + dp[k + 1][r] + matrix[l].first * matrix[k].second * matrix[r].second);
            }
        }
    }
    lli ans = 0;
    for (int l = 1; l <= n; l++) {
        ans = max(ans, dp[l][l + n - 1]);
    }
    printf("%lli\n", ans);

    return 0;
}
