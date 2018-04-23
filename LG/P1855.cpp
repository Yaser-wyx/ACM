#include <bits/stdc++.h>

using namespace std;
/**
 *  Created with IntelliJ Clion.
 *  @author  WXY
 *  @Date: 2018-04-22
 *  @Time: 16:42
 *  To change this template use File | Settings | File Templates.
 * 
 */
#define mset(t, x) memset(t,x,sizeof(t))
#define loop(a, b, c) for(int a=b;a<=c;a++)
#define loop2(a, b, c) for(int a=b;a>=c;a--)
#define maxn 105
#define maxm 250
int n, m, t;
pair<int, int> wishes[maxn];
int dp[maxm][maxm];

int P1855() {
    scanf("%d%d%d", &n, &m, &t);
    loop(i, 1, n) {
        scanf("%d%d", &wishes[i].first, &wishes[i].second);
    }
    mset(dp, 0);
    loop(i, 1, n) {
        loop2(j, m, wishes[i].first) {
            loop2(k, t, wishes[i].second) {
                dp[j][k] = max(dp[j][k], dp[j - wishes[i].first][k - wishes[i].second] + 1);
            }
        }
    }
    printf("%d\n", dp[m][t]);
    return 0;
}