#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
/**
 *  Created with IntelliJ Clion.
 *  @author  wanyu
 *  @Date: 2018-04-16
 *  @Time: 14:01
 *  To change this template use File | Settings | File Templates.
 * 
 */

#define mset(t, x) memset(t,x,sizeof(t))
#define maxn 10006
int n, m;

int P1164() {

    int cost[300];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cost[i]);
    }
    int dp[maxn];
    mset(dp, -1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= cost[i]; j--) {
            if (dp[j - cost[i]] > 0) {
                if (dp[j] < 0) {
                    dp[j] = dp[j - cost[i]];
                } else {
                    dp[j] = dp[j - cost[i]] + dp[j];
                }
            }
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}